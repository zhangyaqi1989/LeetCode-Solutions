class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        parents = list(range(n + 1))
        def find(x):
            if parents[x] == x:
                return x
            else:
                parents[x] = find(parents[x])
                return parents[x]
        for x, y in edges:
            rx, ry = find(x), find(y)
            if rx == ry:
                return [x, y]
            else:
                parents[rx] = ry
