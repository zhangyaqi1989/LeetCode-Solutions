class Solution:
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        s = list(range(1, n + 1))
        res = ''
        i = 0
        k -= 1
        for i in range(n):
            unit = math.factorial(n - i - 1)
            quot, k = divmod(k, unit)
            res += str(s[quot])
            del s[quot]
        return res