class Solution:
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        sign = -1 if dividend * divisor < 0 else +1
        a, b = abs(dividend), abs(divisor)
        res = 0
        while a >= b:
            temp, unit = b, 1
            while a >= temp:
                a -= temp
                res += unit
                temp *= 10
                unit *= 10
        res *= sign
        return res if -2**31 <= res <= 2**31 - 1 else 2**31 - 1