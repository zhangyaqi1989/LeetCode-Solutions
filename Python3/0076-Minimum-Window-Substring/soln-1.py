class Solution:
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        # pochmann is a master...
        missing, need = len(t), collections.Counter(t)
        i = I = J = 0
        for j, ch in enumerate(s, 1):
            missing -= need[ch] > 0
            need[ch] -= 1
            if not missing:
                while i < j and need[s[i]] < 0:
                    need[s[i]] += 1
                    i += 1
                if J == 0 or j - i < J - I:
                    I, J = i, j
        return s[I:J]