# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        def dfs(node, mn=math.inf, mx=-math.inf):
            if node:
                mn = min(mn, node.val)
                mx = max(mx, node.val)
                dfs(node.left, mn, mx)
                dfs(node.right, mn, mx)
            else:
                self.ans = max(self.ans, mx - mn)
        self.ans = 0
        dfs(root)
        return self.ans
