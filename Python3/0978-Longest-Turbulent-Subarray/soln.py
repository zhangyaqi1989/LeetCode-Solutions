class Solution:
    def maxTurbulenceSize(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        inc, dec = 1, 1
        ans = 1
        n = len(A)
        for i in range(1, n):
            a, b = A[i - 1], A[i]
            if b > a:
                inc, dec = dec + 1, 1
            elif b < a:
                inc, dec = 1, inc + 1
            else:
                inc, dec = 1, 1
            ans = max(ans, inc, dec)
        return ans
