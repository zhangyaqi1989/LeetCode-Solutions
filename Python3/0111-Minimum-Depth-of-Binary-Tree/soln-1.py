# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        l, r = self.minDepth(root.left), self.minDepth(root.right)
        return 1 + max(l, r) if min(r, l) == 0 else 1 + min(l, r)