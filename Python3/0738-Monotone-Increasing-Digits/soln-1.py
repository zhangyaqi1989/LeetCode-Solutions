class Solution:
    def monotoneIncreasingDigits(self, N: int) -> int:
        digits = [int(d) for d in str(N)]
        n = len(digits)
        end = n
        for i in range(n - 1, 0, -1):
            if digits[i - 1] > digits[i]:
                digits[i - 1] -= 1
                end = i
        digits[end:] = [9] * (n - end)
        return int(''.join(map(str, digits)))
