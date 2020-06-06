class Solution:
    def findTargetSumWays(self, nums, S):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        dp = {0 : 1}
        for num in nums:
            temp_dp = {}
            for key in dp.keys():
                temp_dp[key + num] = temp_dp.get(key + num, 0) + dp[key]
                temp_dp[key - num] = temp_dp.get(key - num, 0) + dp[key]
            dp = temp_dp
        return dp.get(S, 0)