# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def minMeetingRooms(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """
        pairs = [(interval.start, 1) for interval in intervals] + [(interval.end, 0) for interval in intervals]
        res, cnt = 0, 0
        for _, kind in sorted(pairs):
            if kind == 0:
                cnt -= 1
            else:
                cnt += 1
                if cnt > res: res = cnt
        return res
        