# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        def helper(node):
            if node:
                ld, lroot = helper(node.left)
                rd, rroot = helper(node.right)
                if ld == rd:
                    return ld + 1, node
                elif ld < rd:
                    return rd + 1, rroot
                else:
                    return ld + 1, lroot
            else:
                return 0, None
        _, ans = helper(root)
        return ans
