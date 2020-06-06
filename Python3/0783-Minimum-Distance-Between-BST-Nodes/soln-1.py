# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDiffInBST(self, root: TreeNode) -> int:
        def inorder(node):
            if node:
                inorder(node.left)
                vals.append(node.val)
                inorder(node.right)
        vals = []
        inorder(root)
        return min(b - a for a, b in zip(vals, vals[1:]))
