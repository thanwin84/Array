# time: O(n) and space: O(1)
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        repeating = 0
        for i in range(len(nums)):
            if nums[abs(nums[i])-1] < 0:
                repeating = abs(nums[i])
                break
            else:
                nums[abs(nums[i])-1] = - nums[abs(nums[i])-1]
        return repeating
