class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        nums = sorted(nums)
        for i, x in enumerate(nums):
            if i == len(nums) - 1: return False
            if x == nums[i+1]: return True