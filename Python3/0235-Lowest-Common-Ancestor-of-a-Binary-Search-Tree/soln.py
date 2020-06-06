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
        lb, ub = (p.val, q.val) if p.val < q.val else (q.val, p.val)
        cur = root
        while cur:
            if cur.val < lb:
                cur = cur.right
            elif cur.val > ub:
                cur = cur.left
            else:
                return cur
        return None