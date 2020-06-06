# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def distributeCoins(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # record during post traverse
        self.ans = 0
        def post(node):
            if node:
                lc, rc = post(node.left), post(node.right)
                self.ans += abs(lc) + abs(rc)
                return node.val - 1 + lc + rc
            return 0
        post(root)
        return self.ans
