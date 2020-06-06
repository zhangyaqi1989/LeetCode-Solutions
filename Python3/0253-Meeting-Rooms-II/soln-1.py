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
        d = collections.defaultdict(int)
        for interval in intervals:
            d[interval.start] += 1
            d[interval.end] -= 1
        cnt, ans = 0, 0
        for time in sorted(d.keys()):
            cnt += d[time]
            if cnt > ans: ans = cnt
        return ans
            