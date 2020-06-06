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
        # intervals merge
        low = -1
        ans = []
        for interval in heapq.merge(*schedule, key=operator.attrgetter('start')):
            if low != -1 and interval.start > low:
                ans.append(Interval(low, interval.start))
            low = max(low, interval.end)
        return ans
