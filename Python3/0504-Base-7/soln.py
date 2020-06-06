class Solution:
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        is_neg = num < 0
        num = abs(num)
        lst = [] if num != 0 else [0]
        while num:
            lst.append(num % 7)
            num //= 7
        ans = ''.join(map(str, lst[::-1]))
        return ('-' + ans) if is_neg else ans