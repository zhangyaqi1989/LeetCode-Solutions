# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isUnivalTree(self, root: TreeNode) -> bool:
        return self.dfs(root, root.val)
        
    def dfs(self, node: TreeNode, val: int) -> bool:
        return (not node) or (node.val == val and self.dfs(node.left, val) and self.dfs(node.right, val))
