class Solution:
    def kthFactor(self, n: int, k: int) -> int:
        return next(itertools.islice((f for f in range(1, n + 1) if n % f == 0), k - 1, k), -1)
