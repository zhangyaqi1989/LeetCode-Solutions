class Solution:
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = s.strip()
        i = len(s) - 1
        while i >= 0 and s[i] != ' ':
            i -= 1
        return len(s) - 1 - i
