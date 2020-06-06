class Solution:
    def canPermutePalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        return sum(cnt % 2 for cnt in collections.Counter(s).values()) < 2