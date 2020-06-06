# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        pre_val = None
        modes = []
        mx = 0
        cur_mx = 0
        cur, stack = root, []
        while cur or stack:
            while cur:
                stack.append(cur)
                cur = cur.left
            cur = stack.pop()
            if cur.val != pre_val:
                cur_mx = 0
            cur_mx += 1
            if cur_mx > mx:
                mx = cur_mx
                modes = [cur.val]
            elif cur_mx == mx:
                modes.append(cur.val)
            pre_val = cur.val
            cur = cur.right
        return modes