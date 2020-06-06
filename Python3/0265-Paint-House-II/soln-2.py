class Solution:
    def minCostII(self, costs: List[List[int]]) -> int:
        if not any(costs):
            return 0
        n, k = len(costs), len(costs[0])
        for i in range(1, n):
            first, first_idx, second = math.inf, 0, math.inf
            for j, val in enumerate(costs[i - 1]):
                if val < first:
                    first, first_idx, second = val, j, first
                elif val < second:
                    second = val
            for j in range(k):
                if j == first_idx:
                    costs[i][j] += second
                else:
                    costs[i][j] += first
        return min(costs[-1])
