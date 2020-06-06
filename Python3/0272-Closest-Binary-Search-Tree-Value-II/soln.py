# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def closestKValues(self, root, target, k):
        """
        :type root: TreeNode
        :type target: float
        :type k: int
        :rtype: List[int]
        """
        def traverse(node, vals):
            if node:
                vals.append((abs(node.val - target), node.val))
                traverse(node.left, vals)
                traverse(node.right, vals)
        vals = []
        traverse(root, vals)
        return [val for _, val in heapq.nsmallest(k, vals)]
