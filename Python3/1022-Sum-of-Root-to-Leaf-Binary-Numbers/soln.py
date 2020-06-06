# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        self.ans = 0
        def helper(node, path):
            if node:
                path = path * 2 + node.val
                if not node.left and not node.right:
                    self.ans += path
                helper(node.left, path)
                helper(node.right, path)
        helper(root, 0)
        return self.ans % (10**9 + 7)
