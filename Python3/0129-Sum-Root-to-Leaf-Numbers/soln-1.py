# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        self.ans = 0
        def dfs(node, val):
            if node is not None:
                if node.left is None and node.right is None:
                    self.ans += val * 10 + node.val
                else:
                    if node.left is not None:
                        dfs(node.left, val * 10 + node.val)
                    if node.right is not None:
                        dfs(node.right, val * 10 + node.val)
        dfs(root, 0)
        return self.ans
        
