class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = ''.join(ch.lower() for ch in s if ch.isalnum())
        half = len(s) // 2
        return not half or s[:half] == s[-half:][::-1]