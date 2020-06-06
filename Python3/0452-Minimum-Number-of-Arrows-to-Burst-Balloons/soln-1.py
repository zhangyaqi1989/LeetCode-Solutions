class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        cnt = 0
        low = -math.inf
        for start, end in sorted(points, key=operator.itemgetter(1)):
            if start > low:
                cnt += 1
                low = end
        return cnt
