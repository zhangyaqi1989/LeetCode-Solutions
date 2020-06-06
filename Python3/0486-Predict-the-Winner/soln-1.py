class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        memo = {}
        def compute_score(s, e):
            if (s, e) in memo:
                return memo[s, e]
            if s == e:
                ans = 0
            elif s + 1 == e:
                ans = nums[s]
            else:
                total = sum(nums[s:e])
                left = total - compute_score(s + 1, e)
                right = total - compute_score(s, e - 1)
                ans = max(left, right)
            memo[s, e] = ans
            return ans
        return compute_score(0, len(nums)) >= sum(nums) / 2
