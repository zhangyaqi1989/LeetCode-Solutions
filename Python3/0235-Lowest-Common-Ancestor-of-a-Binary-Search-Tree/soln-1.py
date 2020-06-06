# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        min_v, max_v = (p.val, q.val) if p.val < q.val else (q.val, p.val)
        while root:
            if root.val > max_v:
                root = root.left
            elif root.val < min_v:
                root = root.right
            else:
                return root
