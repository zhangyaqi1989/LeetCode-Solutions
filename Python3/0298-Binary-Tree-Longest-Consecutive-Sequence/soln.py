# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def longestConsecutive(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root: return 0
        stack = [(root, 1)]
        ans = 1
        while stack:
            node, cnt = stack.pop()
            if node.left:
                stack.append((node.left, cnt + 1 if node.left.val == node.val + 1 else 1))
            if node.right:
                stack.append((node.right, cnt + 1 if node.right.val == node.val + 1 else 1))
            if cnt > ans: ans = cnt
        return ans