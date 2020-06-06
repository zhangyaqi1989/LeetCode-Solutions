class Solution:
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        cnt, low = 0, float('-inf')
        for start, end in sorted(points, key=lambda x : x[1]):
            if start > low:
                low = end
                cnt += 1
        return cnt