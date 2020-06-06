# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root, target):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: int
        """
        memo = {0:1}
        self.ans = 0
        def helper(node, cur):
            if node:
                cur += node.val
                need = cur - target
                self.ans += memo.get(need, 0)
                memo[cur] = memo.get(cur, 0) + 1
                helper(node.left, cur)
                helper(node.right, cur)
                memo[cur] = memo.get(cur, 0) - 1
        helper(root, 0)
        return self.ans