class Solution:
    def longestPalindrome(self, s: str) -> str:
        def helper(s):
            n = len(s)
            P = [0] * n
            c = 0
            r = 0
            mx = 0
            ans = ""
            for i in range(n):
                mirror = 2 * c - i
                if i < r:
                    P[i] = min(P[mirror], r - i)
                lo = i - (1 + P[i])
                hi = i + (1 + P[i])
                while lo >= 0 and hi < n and s[lo] == s[hi]:
                    P[i] += 1
                    lo -= 1
                    hi += 1
                if i + P[i] > r:
                    r = i + P[i]
                    c = i
                    if P[i] > mx:
                        mx = P[i]
                        ans = s[i - P[i]:i + P[i]]
            return ''.join(ch for ch in ans if ch != '#')
        lst = []
        for ch in s:
            lst.append('#')
            lst.append(ch)
        lst.append('#')
        return helper(lst)
