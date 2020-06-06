class Solution:
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        chs = string.ascii_uppercase
        ans = []
        while n:
            n -= 1
            ans.append(chs[n % 26])
            n //= 26
        return ''.join(ans[::-1])