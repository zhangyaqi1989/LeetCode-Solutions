class Solution:
    def reformat(self, s: str) -> str:
        digits = [ch for ch in s if ch.isdigit()]
        alphas = [ch for ch in s if ch.isalpha()]
        if abs(len(digits) - len(alphas)) > 1:
            return ""
        else:
            a, b = digits, alphas
            if len(a) < len(b):
                a, b = b, a
            ans = [''] * (len(a) + len(b))
            ans[::2] = a
            ans[1::2] = b
            return ''.join(ans)
