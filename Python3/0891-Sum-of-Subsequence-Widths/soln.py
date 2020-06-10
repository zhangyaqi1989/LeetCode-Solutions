class Solution:
    def sumSubseqWidths(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        n = len(A)
        left, right = 1, 2 ** (n - 1)
        ans = 0
        mod = 10**9 + 7
        for i, num in enumerate(sorted(A)):
            ans += (left - right) * num
            left *= 2
            right //= 2
        return ans % mod
