class Solution:
    def shortestPalindrome(self, s: str) -> str:
        # c a t a c b # b c a t a c
        ns = s + "#" + s[::-1]
        n = len(ns)
        fail = [0] * n
        j = 1
        k = 0
        while j < n:
            if ns[j] == ns[k]:
                fail[j] = k + 1
                j += 1
                k += 1
            elif k > 0:
                k = fail[k - 1]
            else:
                j += 1
        return s[fail[-1]:][::-1] + s
