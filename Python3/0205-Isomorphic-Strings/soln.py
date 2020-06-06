class Solution:
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        mst, mts = {}, {}
        for cs, ct in zip(s, t):
            if cs in mst:
                if mst[cs] != ct:
                    return False
            else:
                mst[cs] = ct
            if ct in mts:
                if mts[ct] != cs:
                    return False
            else:
                mts[ct] = cs
        return True