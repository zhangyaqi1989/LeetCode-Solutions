class Solution:
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        lo, hi = 1, num
        while lo <= hi:
            mid = (lo + hi) >> 1
            if mid * mid == num:
                return True
            elif mid * mid < num:
                lo = mid + 1
            else:
                hi = mid - 1
        return False
