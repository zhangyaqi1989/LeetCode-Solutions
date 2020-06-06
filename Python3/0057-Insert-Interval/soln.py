# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        l, r = 0, len(intervals) - 1
        while l <= r:
            mid = (l + r) >> 1
            if intervals[mid].start == newInterval.start:
                idx = mid
                break
            elif intervals[mid].start < newInterval.start:
                l = mid + 1
            else:
                r = mid - 1
        else:
            idx = l
        intervals.insert(idx, newInterval)
        stack = []
        for interval in intervals:
            if not stack or interval.start > stack[-1].end:
                stack.append(interval)
            else:
                stack[-1].end = max(stack[-1].end, interval.end)
        return stack