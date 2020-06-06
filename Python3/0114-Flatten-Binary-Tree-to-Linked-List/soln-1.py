# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        self.pre = None
        def traverse(node):
            if node:
                traverse(node.right)
                traverse(node.left)
                node.right, self.pre = self.pre, node
                node.left = None
        traverse(root)