class Solution(object):
    def findStrobogrammatic(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        # find all numbers
        if n & 1:
            ans = ['0', '1', '8']
        else:
            ans = ['']
        pairs = ['00', '11', '88', '69', '96']
        while n > 1:
            n -= 2
            ans = [pair[0] + item + pair[1] for item in ans for pair in pairs[n<2:]]
        return ans