class Solution(object):
    def maxDistance(self, arrays):
        """
        :type arrays: List[List[int]]
        :rtype: int
        """
        mx_dis, mn, mx = 0, 10000, -10000
        for array in arrays:
            mx_dis = max(mx_dis, mx - array[0], array[-1] - mn)
            mn, mx = min(mn, array[0]), max(mx, array[-1])
        return mx_dis
