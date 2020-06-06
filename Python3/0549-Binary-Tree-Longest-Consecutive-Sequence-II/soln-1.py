# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def longestConsecutive(self, root: TreeNode) -> int:
        self.ans = 0
        def postorder(node):
            if node:
                l_inc, l_dec = postorder(node.left)
                r_inc, r_dec = postorder(node.right)
                inc, dec = 1, 1
                if node.left and node.left.val == node.val + 1:
                    inc = max(inc, l_inc + 1)
                if node.right and node.right.val == node.val + 1:
                    inc = max(inc, r_inc + 1)
                if node.right and node.right.val == node.val - 1:
                    dec = max(dec, r_dec + 1)
                if node.left and node.left.val == node.val - 1:
                    dec = max(dec, l_dec + 1)
                self.ans = max(self.ans, inc + dec - 1)
                # print(node.val, inc, dec)
                return inc, dec
            else:
                return 0, 0
        postorder(root)
        return self.ans
