class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        # use union find
        n = len(edges)
        parents = list(range(n))
        def find(x):
            if parents[x] == x:
                return x
            else:
                parents[x] = find(parents[x])
                return parents[x]
        for u, v in edges:
            ru, rv = find(u - 1), find(v - 1)
            if ru == rv:
                return [u, v]
            else:
                parents[ru] = rv
