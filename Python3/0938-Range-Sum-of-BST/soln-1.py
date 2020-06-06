# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rangeSumBST(self, root, L, R):
        """
        :type root: TreeNode
        :type L: int
        :type R: int
        :rtype: int
        """
        stack, ans = [(root, L, R)], 0
        while stack:
            node, l, r = stack.pop()
            if node and r >= l:
                if node.val < l:
                    stack.append((node.right, l, r))
                elif node.val > r:
                    stack.append((node.left, l, r))
                else:
                    ans += node.val
                    stack.append((node.left, l, node.val - 1))
                    stack.append((node.right, node.val + 1, r))
        return ans