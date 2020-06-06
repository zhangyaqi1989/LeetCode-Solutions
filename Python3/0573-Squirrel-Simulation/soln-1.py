class Solution:
    def minDistance(self, height, width, tree, squirrel, nuts):
        """
        :type height: int
        :type width: int
        :type tree: List[int]
        :type squirrel: List[int]
        :type nuts: List[List[int]]
        :rtype: int
        """
        tx, ty = tree
        sx, sy = squirrel
        distances = [abs(x - tx) + abs(y - ty) for x, y in nuts]
        return 2 * sum(distances) + min(abs(sx - x) + abs(sy - y) - distances[i] for i, (x, y) in enumerate(nuts))