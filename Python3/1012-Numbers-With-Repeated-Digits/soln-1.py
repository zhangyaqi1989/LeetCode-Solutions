class Solution:
    def numDupDigitsAtMostN(self, N: int) -> int:
        digits = list(map(int, str(N + 1)))
        uniques = 0
        n = len(digits)
        cur = 9
        def func(m, n):
            return 1 if n == 0 else m * func(m - 1, n - 1)
        for i in range(1, n):
            uniques += cur
            cur *= 10 - i
        seen = [False] * 10
        for i, d in enumerate(digits):
            start = 1 if i == 0 else 0
            for y in range(start, d):
                if seen[y]:
                    continue
                # unique numbers of composed of 9 - i digits
                # of length n - i - 1
                uniques += func(9 - i, n - i - 1)
            if seen[d]:
                break
            seen[d] = True
        return N - uniques
