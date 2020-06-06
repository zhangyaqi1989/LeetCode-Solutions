# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def longestUnivaluePath(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.ans = 0
        def helper(node, parent=None):
            if not node:
                return 0
            l = helper(node.left, node)
            r = helper(node.right, node)
            l = l + 1 if node.left and node.val == node.left.val else 0
            r = r + 1 if node.right and node.val == node.right.val else 0
            self.ans = max(self.ans, l + r)
            return max(l, r)
        helper(root)
        return self.ans
