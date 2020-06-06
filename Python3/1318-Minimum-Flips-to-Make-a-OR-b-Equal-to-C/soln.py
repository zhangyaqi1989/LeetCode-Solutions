class Solution:
    def minFlips(self, a: int, b: int, c: int) -> int:
        n = max(len(bin(a)[2:]), len(bin(b)[2:]), len(bin(c)[2:]))
        def convert(num, n):
            ans = bin(num)[2:]
            return ans if n == len(ans) else '0' * (n - len(ans)) + ans
        sa, sb, sc = convert(a, n), convert(b, n), convert(c, n)
        cnt = 0
        for ca, cb, cc in zip(sa, sb, sc):
            if cc == '0':
                cnt += (ca == '1') + (cb == '1')
            else:
                if ca == '0' and cb == '0':
                    cnt += 1
        return cnt
