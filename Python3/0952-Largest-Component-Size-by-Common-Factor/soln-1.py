class Solution:
    def largestComponentSize(self, A: List[int]) -> int:
        n = len(A)
        factors = [[] for _ in range(n)]
        for i, num in enumerate(A):
            f = 2
            while f * f <= num:
                if num % f == 0:
                    while num % f == 0:
                        num //= f
                    factors[i].append(f)
                f += 1
            if num > 1 or not factors[i]:
                factors[i].append(num)
        parents = list(range(n))
        sizes = [1] * n
        self.mx_size = 1
        def find(x):
            if parents[x] == x:
                return x
            parents[x] = find(parents[x])
            return parents[x]
        def unite(x, y):
            rx, ry = find(x), find(y)
            if rx != ry:
                parents[rx] = ry
                sizes[ry] += sizes[rx]
                self.mx_size = max(self.mx_size, sizes[ry])
        prime_to_idx = {}
        for i, fs in enumerate(factors):
            for f in fs:
                if f not in prime_to_idx:
                    prime_to_idx[f] = i
                else:
                    unite(prime_to_idx[f], i)
        return self.mx_size
