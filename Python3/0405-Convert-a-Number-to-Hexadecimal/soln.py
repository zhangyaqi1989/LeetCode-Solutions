class Solution:
    def toHex(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return '0'
        elif num < 0:
            num += 2 ** 32
        digits = '0123456789abcdef'
        ans = []
        while num:
            ans.append(digits[num % 16])
            num //= 16
        return ''.join(ans[::-1])
