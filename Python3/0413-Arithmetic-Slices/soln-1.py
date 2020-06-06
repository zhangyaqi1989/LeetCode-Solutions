class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        # dp[i] is the number of arithmetic sequences end at A[i]
        # dp[i] = dp[i - 1] + 1 if A[i] - A[i - 1] == A[i - 1] - A[i - 2]
        dp = [0] * len(A)
        for i in range(2, len(A)):
            if A[i] - A[i - 1] == A[i - 1] - A[i - 2]:
                dp[i] = dp[i - 1] + 1
        return sum(dp)
