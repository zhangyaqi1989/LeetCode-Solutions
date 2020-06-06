class Solution:
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        ans = [0]
        for i in range(n):
            inc = 2 ** i
            ans += [x + inc for x in reversed(ans)]
        return ans
