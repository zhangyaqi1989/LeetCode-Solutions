# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.ans = 1
        def helper(node):
            if not node:
                return 0
            l = helper(node.left)
            r = helper(node.right)
            self.ans = max(self.ans, l + r + 1)
            return 1 + max(l, r)
        helper(root)
        return self.ans - 1