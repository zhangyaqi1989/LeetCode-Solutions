class Solution:
    def strWithout3a3b(self, A, B):
        """
        :type A: int
        :type B: int
        :rtype: str
        """
        a, b = 'a', 'b'
        if B > A:
            a, b = b, a
            A, B = B, A
        ans = []
        while A:
            if A:
                ans.append(a * min(A, 2))
                A -= min(A, 2)
            if B:
                ans.append(b)
                B -= 1
        i = len(ans) - 1
        while B:
            ans[i] += b
            B -= 1
            i -= 2
        return ''.join(ans)
