class Solution:
    def longestPalindrome(self, s: str) -> str:
        lst = []
        for ch in s:
            lst.append('#')
            lst.append(ch)
        lst.append('#')
        S = ''.join(lst)
        def helper(S):
            mx = 0
            n = len(S)
            P = [0] * n
            c = 0
            r = 0
            ans = ""
            for i, ch in enumerate(S):
                mirror = 2 * c - i
                if i < r:
                    P[i] = min(P[mirror], r - i)
                lo = i - (P[i] + 1)
                hi = i + (P[i] + 1)
                while lo >= 0 and hi < n and S[lo] == S[hi]:
                    lo -= 1
                    hi += 1
                    P[i] += 1
                if i + P[i] > r:
                    r = i + P[i]
                    c = i
                    if P[i] > mx:
                        mx = P[i]
                        ans = S[i - P[i]:i + P[i] + 1]
            return ans
        return ''.join(ch for ch in helper(S) if ch != '#')
