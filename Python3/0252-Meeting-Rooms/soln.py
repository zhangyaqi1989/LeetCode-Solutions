# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def canAttendMeetings(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: bool
        """
        time = float('-inf')
        intervals.sort(key=lambda interval: (interval.start, interval.end))
        for interval in intervals:
            if interval.start < time:
                return False
            time = interval.end
        return True