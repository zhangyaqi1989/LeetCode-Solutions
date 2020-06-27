class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        def factor(n):
            f = 1
            while f <= n:
                if n % f == 0:
                    yield f
                f += 1
        factors = list(factor(n))
        return next(itertools.islice(factor(n), k - 1, k), -1)
