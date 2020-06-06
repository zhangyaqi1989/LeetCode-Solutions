# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recoverTree(self, root):
        """
        :type root: TreeNode
        :rtype: void Do not return anything, modify root in-place instead.
        """
        # do in-order traverse
        swap = [None, None]
        cur = root
        stack = []
        pre = TreeNode(float('-inf'))
        while cur or stack:
            while cur:
                stack.append(cur)
                cur = cur.left
            cur = stack.pop()
            if cur.val < pre.val:
                if not swap[0]: swap[0] = pre
                swap[1] = cur
            pre = cur
            cur = cur.right
        swap[0].val, swap[1].val = swap[1].val, swap[0].val