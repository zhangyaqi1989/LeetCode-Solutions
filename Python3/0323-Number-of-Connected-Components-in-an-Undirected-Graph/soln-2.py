class Solution:
    def countComponents(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        parents = list(range(n))
        sizes = [1] * n
        def find(x):
            if parents[x] != x:
                parents[x] = find(parents[x])
            return parents[x]
        def union(x, y):
            px, py = find(x), find(y)
            sx, sy = sizes[px], sizes[py]
            if sx <= sy:
                parents[px] = py
                sizes[py] += sizes[px]
            else:
                parents[py] = px
                sizes[px] += sizes[py]
        for x, y in edges:
            union(x, y)
        for i in range(n):
            find(i)
        return len(set(parents))
