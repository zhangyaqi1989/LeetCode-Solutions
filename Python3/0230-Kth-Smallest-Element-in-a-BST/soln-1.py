# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        self.k = k
        self.ans = None
        def helper(node):
            if self.k < 0:
                return
            if node:
                helper(node.left)
                self.k -= 1
                if self.k == 0:
                    self.ans = node.val
                helper(node.right)
        helper(root)
        return self.ans