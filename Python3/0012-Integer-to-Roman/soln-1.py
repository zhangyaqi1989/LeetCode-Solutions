class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        symbols = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']
        units = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        ans, idx = '', 0
        while num != 0:
            if num >= units[idx]:
                q, num = divmod(num, units[idx])
                ans += symbols[idx] * q
            idx += 1
        return ans