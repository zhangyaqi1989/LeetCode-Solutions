class Solution:
    def findNthDigit(self, n: int) -> int:
        nnums = 9
        d = 1
        while n > 0:
            bits = nnums * d
            if n > bits:
                n -= bits
            else:
                n -= 1
                q, r = divmod(n, d)
                s = str(10 ** (d - 1) + q)
                return int(s[r])
            d += 1
            nnums *= 10
