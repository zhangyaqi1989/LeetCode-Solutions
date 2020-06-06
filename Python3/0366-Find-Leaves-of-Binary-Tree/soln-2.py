# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        d = collections.defaultdict(list)
        def helper(node):
            if not node:
                return 0
            l, r = helper(node.left), helper(node.right)
            ans = max(l, r) + 1
            d[ans].append(node.val)
            return ans
        helper(root)
        return list(d.values())