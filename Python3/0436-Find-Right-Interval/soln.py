# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def findRightInterval(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[int]
        """
        m = {interval.start : i for i, interval in enumerate(intervals)}
        lefts = sorted(interval.start for interval in intervals)
        ans = []
        for interval in intervals:
            end = interval.end
            idx = bisect.bisect_left(lefts, end)
            if idx == len(lefts):
                ans.append(-1)
            else:
                ans.append(m[lefts[idx]])
        return ans
