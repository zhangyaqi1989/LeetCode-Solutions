# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        acc = 0
        cur = root
        stack = []
        while cur or stack:
            while cur:
                stack.append(cur)
                cur = cur.right
            cur = stack.pop()
            temp = cur.val
            cur.val += acc
            acc += temp
            cur = cur.left
        return root