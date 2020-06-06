# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def findRightInterval(self, intervals: List[Interval]) -> List[int]:
        starts = sorted([(interval.start, i) for i, interval in enumerate(intervals)])
        n = len(intervals)
        ans = [-1] * len(intervals)
        for i in range(n):
            idx = bisect.bisect_left(starts, (intervals[i].end, 0))
            if idx != n:
                ans[i] = starts[idx][1]
        return ans
