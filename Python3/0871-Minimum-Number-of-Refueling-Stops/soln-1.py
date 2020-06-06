class Solution:
    def minRefuelStops(self, target, startFuel, stations):
        """
        :type target: int
        :type startFuel: int
        :type stations: List[List[int]]
        :rtype: int
        """
        cur = startFuel
        pq = []
        ans = 0
        i, n = 0, len(stations)
        while cur < target:
            while i < n and cur >= stations[i][0]:
                heapq.heappush(pq, -stations[i][1])
                i += 1
            if not pq:
                return -1
            fuel = abs(heapq.heappop(pq))
            cur += fuel
            ans += 1
        return ans
