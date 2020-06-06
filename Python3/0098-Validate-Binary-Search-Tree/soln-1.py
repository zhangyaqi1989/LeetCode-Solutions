# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        self.prev = None
        def valid(node):
            if node:
                if not valid(node.left):
                    return False
                if self.prev and self.prev.val >= node.val:
                    return False
                self.prev = node
                return valid(node.right)
            else:
                return True
        return valid(root)
