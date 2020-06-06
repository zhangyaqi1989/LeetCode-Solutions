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
        distance = 2 * sum(abs(x - tx) + abs(y - ty) for x, y in nuts)
        return distance + min(abs(sx - x) + abs(sy - y) - abs(tx - x) - abs(ty - y) for x, y in nuts)