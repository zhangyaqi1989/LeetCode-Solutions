# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getMinimumDifference(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        pre = None
        ans = float('inf')
        cur, stack = root, []
        while cur or stack:
            while cur:
                stack.append(cur)
                cur = cur.left
            cur = stack.pop()
            if pre is not None:
                ans = min(ans, cur.val - pre)
                if ans == 0:
                    return 0
            pre = cur.val
            cur = cur.right
        return ans