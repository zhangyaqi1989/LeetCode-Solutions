# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        # need to collect the leafs
        def dfs(node):
            if not node: return
            if not node.left and not node.right: yield node.val
            for val in dfs(node.left): yield val
            for val in dfs(node.right): yield val
        return all(v1 == v2 for v1, v2 in itertools.zip_longest(dfs(root1), dfs(root2), fillvalue=None))