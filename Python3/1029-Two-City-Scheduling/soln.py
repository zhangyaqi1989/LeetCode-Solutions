class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        N = len(costs) / 2
        nums = [(b - a, i) for i, (a, b) in enumerate(costs)]
        cnt = 0
        ans = 0
        for _, i in sorted(nums):
            if cnt < N:
                ans += costs[i][1]
            else:
                ans += costs[i][0]
            cnt += 1
        return ans
