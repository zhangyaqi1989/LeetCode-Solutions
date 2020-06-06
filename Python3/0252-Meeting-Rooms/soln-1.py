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
        for interval in sorted(intervals, key=operator.attrgetter('start')):
            if interval.start >= time:
                time = interval.end
            else:
                return False
        return True