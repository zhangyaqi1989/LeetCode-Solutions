class Solution(object):
    def hasAlternatingBits(self, n):
        """
        :type n: int
        :rtype: bool
        """
        pre = None
        while n:
            bit = n % 2
            n //= 2
            if pre is not None:
                if bit == pre:
                    return False
            pre = bit
        return True
                