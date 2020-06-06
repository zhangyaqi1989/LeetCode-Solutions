class Solution:
    def atMostNGivenDigitSet(self, D: List[str], N: int) -> int:
        digits = list(map(int, str(N + 1)))
        n = len(digits)
        ans = 0
        D = [int(ch) for ch in D]
        for i in range(1, n):
            ans += len(D) ** i
        for i, d in enumerate(digits):
            for y in D:
                if y >= d:
                    break
                ans += len(D) ** (n - 1 - i)
            if d not in D:
                break
        return ans
