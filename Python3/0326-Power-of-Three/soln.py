class Solution:
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        # do it without loop
        # 3 ** (log3(n)) == n
        if n <= 0: return False 
        return 3 ** round(math.log(n) / math.log(3)) == n