# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        stack = [(p, q)]
        while stack:
            v1, v2 = stack.pop()
            if (not v1 or not v2):
                if v1 != v2:
                    return False
            else:
                if v1.val != v2.val:
                    return False
                stack.append((v1.left, v2.left))
                stack.append((v1.right, v2.right))
        return True