# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def traverse(node, val):
            if node is not None:
                val = val * 10 + node.val
                if node.left is None and node.right is None:
                    return val
                else:
                    return traverse(node.left, val) + traverse(node.right, val)
            else:
                return 0
        return traverse(root, 0)
