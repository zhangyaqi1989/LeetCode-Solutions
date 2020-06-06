# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def subtreeWithAllDeepest(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        def helper(node):
            if not node:
                return None, 0
            (node_l, l), (node_r, r) = helper(node.left), helper(node.right)
            if l == r:
                return node, l + 1
            elif l < r:
                return node_r, r + 1
            else:
                return node_l, l + 1
        return helper(root)[0]