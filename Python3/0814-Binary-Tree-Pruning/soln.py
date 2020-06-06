# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pruneTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        def traverse(node):
            if not node:
                return 0
            l, r = traverse(node.left), traverse(node.right)
            if l == 0:
                node.left = None
            if r == 0:
                node.right = None
            return l + r + node.val
        num = traverse(root)
        return root if num else None