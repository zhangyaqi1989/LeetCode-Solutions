# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxSumBST(self, root: TreeNode) -> int:
        # return is_bst, mn, mx, sum
        self.ans = 0
        def postorder(node):
            if node is not None:
                l_is_bst, l_mn, l_mx, l_sum = postorder(node.left)
                r_is_bst, r_mn, r_mx, r_sum = postorder(node.right)
                mn = min(node.val, l_mn, r_mn)
                mx = max(node.val, l_mx, r_mx)
                s = node.val + l_sum + r_sum
                if l_mx < node.val < r_mn and l_is_bst and r_is_bst:
                    is_bst = True
                    self.ans = max(self.ans, s)
                else:
                    is_bst = False
                return is_bst, mn, mx, s
            return True, math.inf, -math.inf, 0
        postorder(root)
        return self.ans
