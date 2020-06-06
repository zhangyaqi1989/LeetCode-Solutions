class Solution:
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        z = x ^ y
        ans = 0
        while z:
            ans += z & 1
            z //= 2
        return ans