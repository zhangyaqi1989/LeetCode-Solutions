class Solution(object):
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        cuts = list(range(-1, n))
        for i in range(n):
            for l, r in ((i, i), (i, i + 1)):
                while l >= 0 and r < n and s[l] == s[r]:
                    cuts[r+1] = min(cuts[l] + 1, cuts[r+1])
                    l, r = l - 1, r + 1
        return cuts[-1]