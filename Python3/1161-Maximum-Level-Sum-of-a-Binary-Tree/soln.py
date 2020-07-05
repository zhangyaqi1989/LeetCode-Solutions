# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        level_num = 1
        frontier = [root]
        mx = -math.inf
        mx_level = 0
        while frontier:
            next_level = []
            cur = 0
            for node in frontier:
                cur += node.val
                if node.left is not None:
                    next_level.append(node.left)
                if node.right is not None:
                    next_level.append(node.right)
            frontier = next_level
            if cur > mx:
                mx = cur
                mx_level = level_num
            level_num += 1
        return mx_level
