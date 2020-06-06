from functools import lru_cache
class Solution:
    def largestSumOfAverages(self, A: List[int], K: int) -> float:
        # dp[i, K] is the largest sum of averages A[i:] with K groups
        prefix = [0]
        for num in A:
            prefix.append(prefix[-1] + num)
        @lru_cache(None)
        def helper(idx, K):
            if idx == len(A):
                return 0
            if K == 1:
                return (prefix[len(A)] - prefix[idx]) / (len(A) - idx)
            # pick [idx : i]
            return max((prefix[i] - prefix[idx]) / (i - idx) + helper(i, K - 1)
                       for i in range(idx + 1, len(A) + 1))
        return helper(0, K)
