# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        ans = []
        for interval in sorted(intervals, key=lambda x : x.start):
            if not ans or interval.start > ans[-1].end:
                ans.append(interval)
            else:
                ans[-1].end = max(interval.end, ans[-1].end)
        return ans