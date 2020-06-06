# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        self.acc = 0
        def dfs(node):
            if node:
                dfs(node.right)
                temp = node.val
                node.val += self.acc
                self.acc += temp
                dfs(node.left)
        dfs(root)
        return root
        
