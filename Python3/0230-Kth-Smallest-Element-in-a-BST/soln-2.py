# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def kthSmallest(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: int
        """
        def helper(node, lst):
            if node:
                x = helper(node.left, lst)
                if lst[0] == 0:
                    return x
                else:
                    lst[0] -= 1
                    if lst[0] == 0:
                        return node.val
                    else:
                        return helper(node.right, lst)
        return helper(root, [k])