class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        cnt = 0
        n = len(intervals)
        for i in range(n):
            a, b = intervals[i]
            if not any(intervals[j][0] <= a and b <= intervals[j][1] for j in range(n) if j != i):
                cnt += 1
        return cnt
