# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pruneTree(self, root: TreeNode) -> TreeNode:
        def helper(node):
            if not node:
                return 0
            else:
                left = helper(node.left)
                right = helper(node.right)
                if left == 0:
                    node.left = None
                if right == 0:
                    node.right = None
                return node.val + left + right
        helper(root)
        return root
