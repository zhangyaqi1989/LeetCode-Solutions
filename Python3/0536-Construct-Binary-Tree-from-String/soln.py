# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def str2tree(self, s):
        """
        :type s: str
        :rtype: TreeNode
        """
        s = '(' + s + ')'
        def Tree(val=None, left=None, right=None):
            if val is None:
                return None
            node = TreeNode(val)
            node.left = left
            node.right = right
            return node
        s = s.replace('(', ',Tree(')
        return eval(s[1:])
