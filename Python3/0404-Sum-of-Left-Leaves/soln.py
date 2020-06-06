# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.ans = 0
        def traverse(node):
            if not node:
                return
            if node.left and not node.left.left and not node.left.right:
                self.ans += node.left.val
            traverse(node.left)
            traverse(node.right)
        traverse(root)
        return self.ans