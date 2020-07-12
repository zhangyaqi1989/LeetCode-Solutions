class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        n = len(nums)
        return sum(nums[i] == nums[j] for i in range(n) for j in range(i + 1, n))
