class Solution:
    # O(n log(n)) solution
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        snums = sorted(nums)
        a, b = 0, len(nums)-1
        x, y = None, None
        while True:
            ab = snums[a] + snums[b]
            if ab == target:
                break
            elif ab < target:
                a += 1
            else:
                b -= 1
        for i in range(len(nums)):
            if nums[i] == snums[a] and x is None:
                x = i
            elif nums[i] == snums[b] and y is None:
                y = i
            if x is not None and y is not None:
                return [x, y]
                