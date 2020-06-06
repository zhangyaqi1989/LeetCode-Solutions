class Solution:
    def maxA(self, N):
        """
        :type N: int
        :rtype: int
        """
        ans = list(range(N + 1))
        for i in range(7, N + 1):
            ans[i] = max(ans[i - 3] * 2, ans[i - 4] * 3, ans[i - 5] * 4)
        return ans[N]
