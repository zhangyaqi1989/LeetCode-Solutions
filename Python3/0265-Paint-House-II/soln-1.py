class Solution:
    def minCostII(self, costs: List[List[int]]) -> int:
        if not any(costs):
            return 0
        n, k = len(costs), len(costs[0])
        for i in range(1, n):
            mn1 = min(costs[i - 1])
            idx = costs[i - 1].index(mn1)
            mn2 = min(costs[i - 1][:idx] + costs[i - 1][idx + 1:])
            for j in range(k):
                if j == idx:
                    costs[i][j] += mn2
                else:
                    costs[i][j] += mn1
        return min(costs[-1])
