# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def longestConsecutive(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def helper(node, parent):
            if not node: return 0, 0
            li, ld = helper(node.left, node)
            ri, rd = helper(node.right, node)
            self.ans = max(self.ans, li + rd + 1, ri + ld + 1)
            if parent.val + 1 == node.val:
                return max(li, ri) + 1, 0
            if parent.val - 1 == node.val:
                return 0, max(ld, rd) + 1
            return 0, 0
        self.ans = 0
        helper(root, root)
        return self.ans