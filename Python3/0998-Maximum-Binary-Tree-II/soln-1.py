# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def insertIntoMaxTree(self, root: TreeNode, val: int) -> TreeNode:
        node = TreeNode(val)
        if root is None:
            return node
        if val > root.val:
            node.left = root
            return node
        else:
            right = self.insertIntoMaxTree(root.right, val)
            root.right = right
            return root
