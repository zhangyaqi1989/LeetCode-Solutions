class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        def factor(n):
            f = 1
            while f <= n:
                if n % f == 0:
                    yield f
                f += 1
        factors = list(factor(n))
        return factors[k - 1] if len(factors) >= k else -1
