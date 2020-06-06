# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def countNodes(self, root: TreeNode) -> int:
        if root is None:
            return 0
        ld, rd = self.compute_depth(root.left), self.compute_depth(root.right)
        if ld == rd:
            return (1 << ld) + self.countNodes(root.right)
        else:
            return (1 << rd) + self.countNodes(root.left)
        
    def compute_depth(self, node):
        if node is None:
            return 0
        return 1 + self.compute_depth(node.left)
