# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        if not root:
            return False
        if not root.left and not root.right:
            if root.val == sum:
                return True
            else:
                return False
        else:
            return any((self.hasPathSum(root.left, sum - root.val), self.hasPathSum(root.right, sum - root.val)))