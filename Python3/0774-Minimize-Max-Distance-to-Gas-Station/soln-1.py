class Solution:
    def minmaxGasDist(self, stations, K):
        """
        :type stations: List[int]
        :type K: int
        :rtype: float
        """
        # this is a binary search problem
        def valid(d):
            return sum((b - a) // d for a, b in zip(stations, stations[1:])) <= K
        l, r = 0, stations[-1] - stations[0]
        while r - l > 0.000001:
            mid = (l + r) / 2
            if valid(mid):
                r = mid
            else:
                l = mid
        return mid