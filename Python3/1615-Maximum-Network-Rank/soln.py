class Solution:
    def maximalNetworkRank(self, n: int, roads: List[List[int]]) -> int:
        degrees = [0] * n
        edge_sets = set()
        for u, v in roads:
            degrees[u] += 1
            degrees[v] += 1
            edge_sets.add(frozenset([u, v]))
        ans = 0
        for u in range(n):
            for v in range(u + 1, n):
                cnt = degrees[u] + degrees[v] - (frozenset([u, v]) in edge_sets)
                ans = max(ans, cnt)
        return ans
