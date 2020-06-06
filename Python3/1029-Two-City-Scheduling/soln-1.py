class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        n = len(costs) // 2
        ans = 0
        i = 0
        for a, b in sorted(costs, key=lambda x : x[0] - x[1]):
            if i < n:
                ans += a
            else:
                ans += b
            i += 1
        return ans

