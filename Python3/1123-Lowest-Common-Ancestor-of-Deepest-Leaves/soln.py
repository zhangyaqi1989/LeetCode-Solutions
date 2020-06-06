# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from functools import lru_cache
class Solution:
    def lcaDeepestLeaves(self, root: TreeNode) -> TreeNode:
        l, r = self.helper(root.left), self.helper(root.right)
        if l == r:
            return root
        elif l > r:
            return self.lcaDeepestLeaves(root.left)
        else:
            return self.lcaDeepestLeaves(root.right)
    @lru_cache(None)
    def helper(self, node):
        if node:
            l, r = self.helper(node.left), self.helper(node.right)
            return max(l, r) + 1
        else:
            return 0
