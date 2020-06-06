class Solution(object):
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        # dp = [0] * (len(cost) + 1)
        # for i in range(2, len(cost) + 1):
        #     dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
        # return dp[-1]
        first, second = 0, 0
        for i in range(2, len(cost) + 1):
            first, second = second, min(first + cost[i - 2], second + cost[i - 1])
        return second