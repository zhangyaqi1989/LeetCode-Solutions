# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root: TreeNode) -> int:
        # maximum path sum
        def postorder(node):
            if node is not None:
                l = postorder(node.left)
                r = postorder(node.right)
                self.ans = max(self.ans, max(l, 0) + max(r, 0) + node.val)
                return node.val + max(max(l, 0), max(r, 0))
            else:
                return 0
        self.ans = -math.inf
        postorder(root)
        return self.ans
