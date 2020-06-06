class Solution:
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        # how to not use string
        if n == 0:
            return [0]
        if n == 1:
            return [0, 1]
        r = self.grayCode(n - 1)
        add = 2 ** (n - 1)
        return r + [add + item for item in reversed(r)]