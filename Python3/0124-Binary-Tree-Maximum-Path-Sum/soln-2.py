# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # how to do it in one traverse
        self.ans = root.val
        def traverse(node):
            if node is not None:
                l, r = traverse(node.left), traverse(node.right)
                l = l if l > 0 else 0
                r = r if r > 0 else 0
                self.ans = max(self.ans, node.val + l + r)
                return node.val + max(l, r)
            else:
                return 0
        traverse(root)
        return self.ans
