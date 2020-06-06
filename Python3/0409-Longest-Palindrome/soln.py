class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        return len(s) - max(0, sum(cnt % 2 for _, cnt in collections.Counter(s).items()) - 1)