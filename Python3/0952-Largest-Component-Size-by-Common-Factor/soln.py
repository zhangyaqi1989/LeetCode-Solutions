class Solution:
    def largestComponentSize(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        n = len(A)
        parent = list(range(n))

        def find(i):
            if parent[i] != i:
                parent[i] = find(parent[i])
            return parent[i]

        def union(i, j):
            parent[find(i)] = find(j)

        factors = collections.defaultdict(list)
        for i, x in enumerate(A):
            for d in range(2, int(math.sqrt(x)) + 1):
                if x % d == 0:
                    while x % d == 0:
                        x //= d
                    factors[d].append(i)
            if x > 1:
                factors[x].append(i)
        for lst in factors.values():
            for a, b in zip(lst, lst[1:]):
                union(a, b)
        for i in range(len(A)):
            find(i)
        return collections.Counter(parent).most_common(1)[0][-1]
