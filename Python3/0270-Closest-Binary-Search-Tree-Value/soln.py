# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def closestValue(self, root, target):
        """
        :type root: TreeNode
        :type target: float
        :rtype: int
        """
        def helper(node, val):
            if not node:
                return (float('inf'), None)
            child = node.left if val <= node.val else node.right
            (d, ans) = helper(child, val)
            return (d, ans) if d < abs(node.val - val) else (abs(node.val - val), node)
        return helper(root, target)[1].val