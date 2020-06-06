class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        if not any(costs):
            return 0
        r, b, g = costs[0]
        n = len(costs)
        for i in range(1, n):
            r, b, g = min(b, g) + costs[i][0], min(r, g) + costs[i][1], min(r, b) + costs[i][2]
        return min(r, b, g)
