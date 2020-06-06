# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        ans = float('-inf')
        def helper(node):
            nonlocal ans
            if not node:
                return 0
            l = helper(node.left)
            r = helper(node.right)
            l = max(l, 0)
            r = max(r, 0)
            ans = max(ans, node.val + l + r)
            return node.val + max(l, r)
        helper(root)
        return ans