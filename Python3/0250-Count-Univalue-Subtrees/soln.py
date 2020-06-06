# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def countUnivalSubtrees(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.count = 0
        def helper(node, val):
            if not node:
                return True
            left = helper(node.left, node.val)
            right = helper(node.right, node.val)
            if not left or not right:
                return False
            self.count += 1
            return node.val == val
        helper(root, 0)
        return self.count