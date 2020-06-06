from functools import lru_cache
class Solution:
    def largestSumOfAverages(self, A: List[int], K: int) -> float:
        @lru_cache(None)
        def helper(n, K):
            if n == K:
                return sum(A[:n])
            if K == 1:
                return sum(A[:n]) / n
            ans = -math.inf
            cur, cnt = 0, 0
            for i in reversed(range(K - 1, n)):
                cnt += 1
                cur += A[i]
                temp = helper(i, K - 1) + cur / cnt
                if temp > ans:
                    ans = temp
            return ans
        return helper(len(A), K)
