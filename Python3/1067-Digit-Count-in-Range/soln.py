class Solution:
    def digitsCount(self, d: int, low: int, high: int) -> int:
        def helper(n, D):
            unit = 1
            ans = 0
            right = 0
            while n != 0:
                d = n % 10
                n //= 10
                if d < D:
                    ans += n * unit
                elif d == D:
                    if D == 0:
                        ans += (n - 1) * unit + right + 1
                    else:
                        ans += n * unit + right + 1
                else: # d > D
                    if D == 0:
                        ans += n * unit
                    else:
                        ans += n * unit + unit
                right += d * unit
                unit *= 10
            return ans
        hi = helper(high, d)
        lo = helper(low - 1, d)
        return helper(high, d) - helper(low - 1, d)
