# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, target: int) -> bool:
        if not root: return False
        if not root.left and not root.right: return root.val == target
        return any(self.hasPathSum(child, target - root.val) for child in (root.left, root.right))
