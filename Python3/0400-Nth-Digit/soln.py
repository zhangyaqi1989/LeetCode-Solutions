class Solution:
    def findNthDigit(self, n):
        """
        :type n: int
        :rtype: int
        """
        # 1 bit: 1 - 9 9
        # 2 bit: 10 - 99 90
        # 3 bit: 100 - 999 900
        unit = 1
        while n:
            num = unit * 9 * 10 ** (unit - 1)
            if n > num:
                n -= num
            else:
                n -= 1
                q, r = divmod(n, unit)
                left = 10 ** (unit - 1)
                return int(str(left + q)[r])
            unit += 1