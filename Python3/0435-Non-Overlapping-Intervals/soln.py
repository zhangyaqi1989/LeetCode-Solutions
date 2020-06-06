# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        cnt, low = 0, float('-inf')
        for interval in sorted(intervals, key=operator.attrgetter('end')):
            if interval.start < low:
                cnt += 1
            else:
                low = interval.end
        return cnt