# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def largestBSTSubtree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        self.ans = 0
        def helper(node):
            if not node:
                return 0, float('inf'), float('-inf'), True
            else:
                lcnt, lmin, lmax, lbst = helper(node.left)
                rcnt, rmin, rmax, rbst = helper(node.right)
                cnt = lcnt + rcnt + 1
                isbst = False
                if lbst and rbst and lmax < node.val < rmin:
                    isbst = True
                    self.ans = max(self.ans, cnt)
                return cnt, min(node.val, lmin, rmin), max(node.val, lmax, rmax), isbst
        helper(root)
        return self.ans