# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.max_level = 0
        self.ans = root.val
        def traverse(node, level):
            if node:
                if level > self.max_level:
                    self.max_level = level
                    self.ans = node.val
                traverse(node.left, level + 1)
                traverse(node.right, level + 1)
        traverse(root, 0)
        return self.ans