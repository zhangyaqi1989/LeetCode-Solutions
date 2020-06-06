# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        vals = []
        def preorder(node):
            if node:
                vals.append(node.val)
                for nei in filter(None, (node.left, node.right)):
                    preorder(nei)
        preorder(root)
        return vals