class Solution:
    def numDupDigitsAtMostN(self, N: int) -> int:
        # 9876 ...
        def pick(m, n):
            # number of ways to pick n from m
            assert(m >= n)
            ans = 1
            for i in range(n):
                ans *= m
                m -= 1
            return ans
        str_N = str(N + 1)
        n = len(str_N)
        uniques = 0
        for i in range(1, n):
            uniques += 9 * pick(9, i - 1)
        seen = set()
        for i, d in enumerate(str_N):
            start = 1 if i == 0 else 0
            d = int(d)
            for y in range(start, d):
                if y in seen:
                    continue
                uniques += pick(9 - i, n - i - 1)
            if d in seen:
                break
            seen.add(d)
        return N - uniques
