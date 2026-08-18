class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        pairs = {}
        for i, num in enumerate(nums):
            if target - num in pairs:
                return [pairs[target - num], i]
            pairs[num] = i
        return []
        