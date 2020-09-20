class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        def manhattan(i, j):
            return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])
        def find(x):
            if parents[x] == x:
                return x
            else:
                parents[x] = find(parents[x])
                return parents[x]
        n = len(points)
        edges = [(manhattan(i, j), i, j) for i in range(n) for j in range(i + 1, n)]
        parents = list(range(n))
        cnt = n
        ans = 0
        for e, x, y in sorted(edges):
            rx, ry = find(x), find(y)
            if rx != ry:
                parents[rx] = ry
                ans += e
                cnt -= 1
                if cnt == 1:
                    break
        return ans
