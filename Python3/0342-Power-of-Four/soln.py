class Solution:
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        while num % 4 == 0 and num > 1:
            num //= 4
        return num == 1
