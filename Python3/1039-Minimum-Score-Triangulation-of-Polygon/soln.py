import functools
class Solution:
    def minScoreTriangulation(self, A: List[int]) -> int:
        @functools.lru_cache(None)
        def helper(nums):
            if len(nums) == 3:
                return nums[0] * nums[1] * nums[-1]
            else:
                res = math.inf
                n = len(nums)
                for i in range(2, n - 1):
                    half1 = nums[:i + 1]
                    half2 = (nums[0],) + nums[i:]
                    res = min(helper(half1) + helper(half2), res)
                return min(res, nums[-1] * nums[0] * nums[1] + helper(nums[1:]))
        return helper(tuple(A))
