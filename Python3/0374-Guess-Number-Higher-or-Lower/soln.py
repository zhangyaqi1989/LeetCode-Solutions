# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        l, r = 1, n
        while l <= r:
            mid = (l + r) >> 1
            g = guess(mid)
            if g == 0:
                return mid
            elif g == 1:
                l = mid + 1
            else:
                r = mid - 1