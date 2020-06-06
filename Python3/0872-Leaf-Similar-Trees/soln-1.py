# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from itertools import zip_longest
class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        def traverse(node):
            if node:
                for val in traverse(node.left):
                    yield val
                if not node.left and not node.right:
                    yield node.val
                for val in traverse(node.right):
                    yield val
        return all(val1 == val2 for val1, val2 in zip_longest(traverse(root1), traverse(root2)))
