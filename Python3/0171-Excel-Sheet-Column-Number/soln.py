class Solution:
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        units = dict(zip(string.ascii_uppercase, range(1, 27)))
        ans = 0
        for ch in s:
            ans = ans * 26 + units[ch]
        return ans