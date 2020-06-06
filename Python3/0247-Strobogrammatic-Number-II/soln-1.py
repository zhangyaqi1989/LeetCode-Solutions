class Solution:
    def findStrobogrammatic(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        ans = ['1', '8', '0'] if n % 2 else ['']
        pairs = (('0', '0'), ('1', '1'), ('8', '8'), ('6', '9'), ('9', '6'))
        while n > 1:
            n -= 2
            ans = [l + item + r for item in ans for l, r in pairs[n<=1:]]
        return ans