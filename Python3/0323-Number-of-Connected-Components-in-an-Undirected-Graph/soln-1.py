class Solution:
    def countComponents(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        parents = list(range(n))
        def find(x):
            if parents[x] != x:
                parents[x] = find(parents[x])
            return parents[x]
        def union(x, y):
            px = find(x)
            py = find(y)
            parents[py] = px
        for x, y in edges:
            union(x, y)
        for i in range(n):
            find(i)
        return len(set(parents))
