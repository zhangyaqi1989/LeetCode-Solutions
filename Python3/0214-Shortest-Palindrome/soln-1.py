class Solution:
    def shortestPalindrome(self, s: str) -> str:
        # longest palindrome substring
        if s == s[::-1]:
            return s
        n = len(s)
        for i in range(1, n):
            ns = s[-i:][::-1] + s
            if ns == ns[::-1]:
                return ns
