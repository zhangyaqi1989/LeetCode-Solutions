# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def countNodes(self, root: 'TreeNode') -> 'int':
        if not root:
            return 0
        l, r = self.height(root.left), self.height(root.right)
        if l == r: # left subtree is complete
            return 2 ** l + self.countNodes(root.right)
        else: # right subtree is complete
            return 2 ** r + self.countNodes(root.left)
    def height(self, root : 'TreeNode') -> 'int':
        if not root:
            return 0
        return 1 + self.height(root.left)
