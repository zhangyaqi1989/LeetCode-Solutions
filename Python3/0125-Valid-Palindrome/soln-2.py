class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = ''.join(ch.lower() for ch in s if ch.isalnum())
        return s == s[::-1]