//time: O(nlogn)
class Pair:
    def __init__(self, value, index):
        self.value = value
        self.index = index
class Solution:
    def getMinDiff(self, arr, n, k):
        if len(arr) == 1 :
            return 0
        visited = []
        possibleHeights = []
        for i in range(n):
            visited.append(0)
            if arr[i] - k >= 0:
                possibleHeights.append(Pair(arr[i] - k, i))
            possibleHeights.append(Pair(arr[i] + k, i))
        possibleHeights = sorted(possibleHeights, key = lambda x: x.value)
        left = 0
        right = 0
        count = 0
        ans = float('inf')
        while right < len(possibleHeights):
            if left + 1 > n:
                break
            visited[possibleHeights[right].index] += 1
            if visited[possibleHeights[right].index] == 1:
                count += 1
            if count == n:
                # check ans until count is less than n
                while count == n:
                    if count == n:
                        ans = min(ans, possibleHeights[right].value - possibleHeights[left].value)
                    visited[possibleHeights[left].index] -= 1
                    if visited[possibleHeights[left].index] == 0:
                        count -= 1
                    left += 1
            right += 1
        return ans
