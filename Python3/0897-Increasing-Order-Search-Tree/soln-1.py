# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def increasingBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        self.pre = None
        def traverse(node):
            if node:
                traverse(node.right)
                left = node.left
                node.left = None
                node.right = self.pre
                self.pre = node
                traverse(left)
        traverse(root)
        return self.pre