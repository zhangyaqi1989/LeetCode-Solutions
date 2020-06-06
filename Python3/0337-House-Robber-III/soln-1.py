# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
# TLE
class Solution:
    def rob(self, root: TreeNode) -> int:
        def helper(node, parent_used=False):
            if not node:
                return 0
            if parent_used:
                return helper(node.left, False) + helper(node.right, False)
            else:
                return max(node.val + helper(node.left, True) + helper(node.right, True), helper(node.left, False) + helper(node.right, False))
        return helper(root, False)
