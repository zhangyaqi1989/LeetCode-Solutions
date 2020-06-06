# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        ans = 0
        def dfs(node, gp=None, p=None):
            if node is not None:
                if gp is not None and gp.val % 2 == 0:
                    nonlocal ans
                    ans += node.val
                dfs(node.left, p, node)
                dfs(node.right, p, node)
        dfs(root)
        return ans
