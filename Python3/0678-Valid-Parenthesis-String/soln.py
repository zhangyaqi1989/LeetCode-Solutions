class Solution:
    def checkValidString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        cmin = cmax = 0
        for ch in s:
            cmax = cmax - 1 if ch == ')' else cmax + 1
            cmin = cmin + 1 if ch == '(' else max(cmin - 1, 0)
            if cmax < 0: return False
        return cmin == 0