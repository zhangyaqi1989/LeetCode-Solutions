# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', nodes: 'List[TreeNode]') -> 'TreeNode':
        need = set(nodes)
        def dfs(root):
            if root is None:
                return None
            if root in need:
                return root
            l, r = dfs(root.left), dfs(root.right)
            if l and r:
                return root
            return l or r
        return dfs(root)
