# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def increasingBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        stack = []
        cur = root
        right = None
        while cur or stack:
            while cur:
                stack.append(cur)
                cur = cur.right
            cur = stack.pop()
            cur.right = right
            temp = cur.left
            cur.left = None
            right = cur
            cur = temp
        return right