# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sufficientSubset(self, root: TreeNode, limit: int) -> TreeNode:
        def helper(node, limit):
            if node is None:
                return None, 0
            node.left, l = helper(node.left, limit - node.val)
            node.right, r = helper(node.right, limit - node.val)
            val = max(l, r) + node.val
            return (node if val >= limit else None), val
        return helper(root, limit)[0]
        
