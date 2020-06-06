# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def tree2str(self, t: TreeNode) -> str:
        def preorder(node):
            if node:
                ans = str(node.val)
                if not node.left and not node.right:
                    return ans
                ans += "({})".format(preorder(node.left))
                if node.right:
                    ans += "({})".format(preorder(node.right))
                return ans
            else:
                return ""
        return preorder(t)
