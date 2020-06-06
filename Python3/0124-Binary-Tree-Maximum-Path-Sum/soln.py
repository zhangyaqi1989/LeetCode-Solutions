# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.ans = float('-inf')
        def helper(node):
            if not node:
                return 0
            l = helper(node.left)
            r = helper(node.right)
            l = l if l > 0 else 0
            r = r if r > 0 else 0
            self.ans = max(self.ans, node.val + l + r)
            return node.val + max(l, r)
        helper(root)
        return self.ans