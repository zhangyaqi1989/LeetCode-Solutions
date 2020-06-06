class Solution(object):
    def minmaxGasDist(self, stations, K):
        """
        :type stations: List[int]
        :type K: int
        :rtype: float
        """
        lo, hi = 10e-6, stations[-1] - stations[0]
        def possible(D):
            return sum((b - a) // D for a, b in zip(stations, stations[1:])) <= K
        while hi - lo > 10e-6:
            mid = (hi + lo) / 2
            if possible(mid):
                hi = mid
            else:
                lo = mid
        return lo