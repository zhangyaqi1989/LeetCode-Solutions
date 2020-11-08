# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def helper(node):
            if node is None:
                return None
            if node == p or node == q:
                return node
            l = helper(node.left)
            r = helper(node.right)
            if l is not None and r is not None:
                return node
            return l or r
        def count(node):
            if node is None:
                return 0
            return (node.val in (p.val, q.val)) + count(node.left) + count(node.right)
        ans = helper(root)
        if ans is not None:
            cnt = count(ans)
        return ans if cnt == 2 else None
