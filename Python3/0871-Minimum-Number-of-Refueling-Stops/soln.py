class Solution:
    def minRefuelStops(self, target, startFuel, stations):
        """
        :type target: int
        :type startFuel: int
        :type stations: List[List[int]]
        :rtype: int
        """
        # dp[i] means maximum distance with ith refuel
        n = len(stations)
        dp = [startFuel] + [0] * n
        for i in range(n): # for every station
            for j in reversed(range(i + 1)):
                if dp[j] >= stations[i][0]:
                    dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1])
        return next((i for i in range(len(dp)) if dp[i] >= target), -1)
