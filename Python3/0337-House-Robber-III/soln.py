# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def helper(node):
            # return a tuple (rob_node, not_rob_node)
            if not node:
                return (0, 0)
            left, right = helper(node.left), helper(node.right)
            rob = node.val + left[1] + right[1]
            not_rob = max(left)+ max(right)
            return (rob, not_rob)
        return max(helper(root))