# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        stack = []
        cur = root
        x = y = pred = None
        while stack or cur is not None:
            while cur:
                stack.append(cur)
                cur = cur.left
            cur = stack.pop()
            if pred is not None and cur.val < pred.val:
                y = cur
                if x is not None:
                    break
                else:
                    x = pred
            pred = cur
            cur = cur.right
        x.val, y.val = y.val, x.val
