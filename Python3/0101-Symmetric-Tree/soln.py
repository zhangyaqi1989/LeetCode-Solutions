# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        return self.isMirror(root.left, root.right)
        
        
    def isMirror(self, left, right):
        if not left or not right:
            return left == right
        return left.val == right.val and self.isMirror(left.right, right.left) and self.isMirror(left.left, right.right)