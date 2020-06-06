"""
# Definition for a QuadTree node.
class Node:
    def __init__(self, val, isLeaf, topLeft, topRight, bottomLeft, bottomRight):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight
"""
class Solution:
    def construct(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: Node
        """
        def is_leaf(r1, r2, c1, c2):
            vals = set()
            for r in range(r1, r2):
                for c in range(c1, c2):
                    vals.add(grid[r][c])
                    if len(vals) > 1:
                        return False
            return True
        def build(r1, r2, c1, c2):
            if r1 >= r2 or c1 >= c2:
                return None
            if is_leaf(r1, r2, c1, c2):
                return Node(grid[r1][c1] == 1, True, None, None, None, None)
            else:
                r_mid = (r1 + r2) >> 1
                c_mid = (c1 + c2) >> 1
                return Node('*', False, build(r1, r_mid, c1, c_mid),
                                        build(r1, r_mid, c_mid, c2),
                                        build(r_mid, r2, c1, c_mid),
                                        build(r_mid, r2, c_mid, c2))
        return build(0, len(grid), 0, len(grid[0]))
