class Solution:
    def minCostToSupplyWater(self, n: int, wells: List[int], pipes: List[List[int]]) -> int:
        edges = [(w, u, v) for u, v, w in pipes] + [(w, 0, i) for i, w in enumerate(wells, 1)]
        parents = list(range(n + 1))
        def find(x):
            if parents[x] == x:
                return x
            else:
                parents[x] = find(parents[x])
                return parents[x]
        cost = 0
        cnt = 0
        for w, x, y in sorted(edges):
            rx, ry = find(x), find(y)
            if rx != ry:
                parents[rx] = ry
                cost += w
                cnt += 1
                if cnt == n:
                    break
        return cost
