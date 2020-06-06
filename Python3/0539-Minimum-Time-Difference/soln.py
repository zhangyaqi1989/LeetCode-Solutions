class Solution:
    def findMinDifference(self, timePoints):
        """
        :type timePoints: List[str]
        :rtype: int
        """
        if len(timePoints) > 1440:
            return 0
        def toMin(time):
            h, m = map(int, time.split(':'))
            return h * 60 + m
        def diff(m1, m2):
            d = abs(m1 - m2)
            return min(d, 1440 - d)
        ms = sorted(list(map(toMin, timePoints)))
        return min(diff(ms[i], ms[i - 1]) for i in range(len(ms)))
