class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        # solve it without converting the integer to a string
        if x < 0:
            return False
        r = 0
        origin = x
        while x:
            r = r * 10 + x % 10
            x //= 10
        return r == origin