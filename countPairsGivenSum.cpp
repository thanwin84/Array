class Solution:
    def getPairsCount(self, arr, n, k):
        lookup = {}
        for i in range(len(arr)):
            try:
                lookup[arr[i]] += 1
            except:
                lookup[arr[i]] = 1
        twice_count = 0
        for i in range(len(arr)):
            if k - arr[i] in lookup:
                twice_count += lookup[k - arr[i]]
            if k - arr[i] == arr[i]:
                twice_count -= 1
        return twice_count//2
