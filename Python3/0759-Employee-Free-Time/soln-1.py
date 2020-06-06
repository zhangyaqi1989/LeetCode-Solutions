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
        lst = sorted(itertools.chain.from_iterable(schedule), key=lambda x: (x.start, x.end))
        low = -1
        ans = []
        for interval in lst:
            if interval.start > low:
                ans.append(Interval(s=low, e=interval.start))
                low = interval.end
            else:
                low = max(low, interval.end)
        return ans[1:]