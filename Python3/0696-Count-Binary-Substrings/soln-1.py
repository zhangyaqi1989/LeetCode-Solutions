class Solution:
    def countBinarySubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        pre, ans = 0, 0
        ch, i = s[0], 0
        for j, val in enumerate(s + '#'):
            if val != ch:
                cur = j - i
                i = j
                ans += min(cur, pre)
                pre = cur
                ch = val
        return ans