class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x : (x[1], x[0]))
        lo = -math.inf
        ans = 0
        for s, e in points:
            if s > lo:
                ans += 1
                lo = e
        return ans
