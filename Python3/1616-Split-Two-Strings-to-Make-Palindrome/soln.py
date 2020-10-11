class Solution:
    def checkPalindromeFormation(self, a: str, b: str) -> bool:
        def is_parlindrome(s, lo, hi):
            while lo < hi and s[lo] == s[hi]:
                lo += 1
                hi -= 1
            return lo >= hi
            
        def check(u, v):
            lo = 0
            hi = len(v) - 1
            while lo < hi and u[lo] == v[hi]:
                lo += 1
                hi -= 1
            return is_parlindrome(u, lo, hi) or is_parlindrome(v, lo, hi)
        return check(a, b) or check(b, a)
