class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        times = collections.Counter()
        for s, e in intervals:
            times[s] += 1
            times[e] -= 1
        mx = cur = 0
        for t in sorted(times):
            cur = cur + times[t]
            mx = max(mx, cur)
        return mx
