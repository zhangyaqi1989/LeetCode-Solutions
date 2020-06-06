# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def isMirror(p, q):
            if not p or not q:
                return p == q
            return p.val == q.val and isMirror(p.left, q.right) and isMirror(p.right, q.left)
        return isMirror(root, root)