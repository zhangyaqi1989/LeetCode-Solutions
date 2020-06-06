class Solution:
    def minCostII(self, costs: List[List[int]]) -> int:
        # 1 5 3
        # 2 9 4
        if not any(costs):
            return 0
        n = len(costs)
        k = len(costs[0])
        for i in range(1, n):
            prev = costs[i - 1]
            mn = min(prev)
            argmin = prev.index(mn)
            second = min(prev[:argmin] + prev[argmin + 1:])
            for j in range(k):
                if j != argmin:
                    costs[i][j] += mn
                else:
                    costs[i][j] += second
        return min(costs[-1])
