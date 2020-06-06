class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) != n - 1:
            return False
        parents = list(range(n))
        def find(x):
            if x == parents[x]:
                return x
            else:
                parents[x] = find(parents[x])
                return parents[x]
        for a, b in edges:
            ra, rb = find(a), find(b)
            # print(ra, rb)
            if ra == rb:
                return False
            parents[ra] = parents[rb]
        return True
