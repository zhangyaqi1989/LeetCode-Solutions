# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        def build_tree_node(x, lnode, rnode):
            "Build tree node with value, left node and right node."
            root = TreeNode(x)
            root.left = lnode
            root.right = rnode
            return root
        
        def build(l, r):
            "Build BST from [l, r]."
            if l == r:
                return [TreeNode(l)]
            elif l > r:
                return [None]
            else:
                return [ build_tree_node(val, lnode, rnode)
                         for val in range(l, r + 1)
                         for lnode in build(l, val - 1)
                         for rnode in build(val + 1, r)]
        return build(1, n) if n > 0 else []