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
        intervals.sort(key=lambda x : x.start)
        heap = []
        for interval in intervals:
            if heap and interval.start >= heap[0]:
                heapq.heapreplace(heap, interval.end)
            else:
                heapq.heappush(heap, interval.end)
        return len(heap)