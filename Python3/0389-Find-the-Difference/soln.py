class Solution:
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        cs, ct = collections.Counter(s), collections.Counter(t)
        for ch in string.ascii_lowercase:
            if cs[ch] < ct[ch]:
                return ch