class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        def toMin(time):
            h, m = map(int, time.split(':'))
            return h * 60 + m
        times = [toMin(time) for time in timePoints]
        times.sort()
        return min((times[i] - times[i - 1]) % 1440 for i in range(len(times)))
