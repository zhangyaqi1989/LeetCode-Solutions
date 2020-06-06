class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        sign = -1 if dividend * divisor < 0 else 1
        a, b = abs(dividend), abs(divisor)
        ans = 0
        while a >= b:
            d = b
            q = 1
            while a >= d:
                a -= d
                ans += q
                d <<= 1
                q <<= 1
        ans *= sign
        INT_MIN, INT_MAX = -(1 << 31), ((1 << 31) - 1)
        return ans if INT_MIN <= ans <= INT_MAX else INT_MAX
