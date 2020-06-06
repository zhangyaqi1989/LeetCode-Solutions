class Solution:
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0:
            return False
        factors = [5, 3, 2]
        for factor in factors:
            while num >= factor:
                if num % factor == 0:
                    num //= factor
                else:
                    break
        return num == 1