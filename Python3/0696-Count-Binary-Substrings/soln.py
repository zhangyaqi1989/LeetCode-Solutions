class Solution:
    def countBinarySubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnts = [len(list(g)) for key, g in itertools.groupby(s)]
        return sum(min(a, b) for a, b in zip(cnts, cnts[1:]))