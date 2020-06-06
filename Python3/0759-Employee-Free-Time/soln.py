# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def employeeFreeTime(self, schedule):
        """
        :type schedule: List[List[Interval]]
        :rtype: List[Interval]
        """
        schedule = list(itertools.chain(*schedule))
        schedule.sort(key=lambda interval: (interval.start, interval.end))
        res = []
        end = float('-inf')
        for interval in schedule:
            s, e = interval.start, interval.end
            if s > end and end != float('-inf'):
                res.append(Interval(end, s))
                end = e
            else:
                end = max(end, e)
        return res