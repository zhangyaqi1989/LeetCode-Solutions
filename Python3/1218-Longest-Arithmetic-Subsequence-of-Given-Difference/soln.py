class Solution:
    def longestSubsequence(self, arr: List[int], diff: int) -> int:
        dp = {}
        for num in arr:
            if num - diff in dp:
                cnt = dp.pop(num - diff)
                dp[num] = max(dp.get(num, 0), cnt + 1)
            else:
                dp[num] = max(dp.get(num, 0), 1)
        return max(dp.values())
