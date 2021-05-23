# single pass - O(n) time and O(1) space
class Solution:
    def trappingWater(self, arr,n):
        #Code here
        maxL = arr[0]
        maxR = arr[n - 1]
        left = 1
        right = n -2
        trappingWater = 0
        while left <= right:
            if maxL <= maxR:
                if arr[left] >= maxL:
                    maxL = arr[left]
                else:
                    trappingWater += maxL - arr[left]
                left += 1
            else:
                if arr[right] >= maxR:
                    maxR = arr[right]
                else:
                    trappingWater += maxR - arr[right]
                right -= 1
        return trappingWater
