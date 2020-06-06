# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def mergeTrees(self, t1, t2):
        """
        :type t1: TreeNode
        :type t2: TreeNode
        :rtype: TreeNode
        """
        if not t1 or not t2:
            return t1 or t2
        t1.val += t2.val
        t1.left, t1.right = self.mergeTrees(t1.left, t2.left), self.mergeTrees(t1.right, t2.right)
        return t1