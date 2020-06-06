class Solution:
    def largestSumOfAverages(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: float
        """
        memo = {}
        def helper(n, k):
            if (n, k) in memo:
                return memo[n, k]
            if k > n:
                return 0
            if k == 1:
                ans = sum(A[:n]) / n
            else:
                ans = 0
                cur = 0
                cnt = 0
                for i in range(n - 1, -1, -1):
                    cur += A[i]
                    cnt += 1
                    ans = max(ans, helper(i, k - 1) + cur / cnt)
            memo[n, k] = ans
            return ans
        return helper(len(A), K)
