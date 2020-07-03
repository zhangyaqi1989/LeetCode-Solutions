# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: TreeNode) -> int:
        # postorder
        def dfs(node):
            if node is not None:
                self.total += node.val
                dfs(node.left)
                dfs(node.right)

        def postorder(node):
            if node is not None:
                sub = postorder(node.left) + postorder(node.right) + node.val
                self.best = max(self.best, sub * (self.total - sub))
                return sub
            else:
                return 0
        self.total = 0
        dfs(root)
        self.best = 0
        postorder(root)
        return self.best % 1000000007
