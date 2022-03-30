class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        maxsum = nums[0]
        cursum = nums[0]
        for n in nums[1:]:
            if cursum < 0:
                cursum = 0
            cursum += n
                
            if cursum > maxsum:
                maxsum = cursum
        return maxsum
    