class Solution:
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        symbols = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']
        units = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        res = ''
        for idx in range(13):
            unit = units[idx]
            if num >= unit:
                res += symbols[idx] * (num // unit)
                num %= unit
            if num == 0: return res
        return res