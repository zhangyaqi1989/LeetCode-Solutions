class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        nums.sort()
        ans = 0
        for val, g in itertools.groupby(nums):
            cnt = len(list(g))
            ans += cnt * (cnt - 1) // 2
        return ans
