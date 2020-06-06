class Solution:
    def isOneEditDistance(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) == len(t):
            return sum(cs != ct for cs, ct in zip(s, t)) == 1
        else:
            if len(s) > len(t):
                s, t = t, s
            # s is shorter
            if len(t) - len(s) > 1:
                return False
            for i, (cs, ct) in enumerate(zip(s, t)):
                if cs != ct:
                    return s[:i] + ct + s[i:] == t
            return True
