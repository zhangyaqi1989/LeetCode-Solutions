# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isCousins(self, root: 'TreeNode', x: 'int', y: 'int') -> 'bool':
        m = {}
        def traverse(node, parent=None, depth=0):
            if node:
                m[node.val] = (parent, depth)
                traverse(node.left, node.val, depth+1)
                traverse(node.right, node.val, depth + 1)
        traverse(root)
        return m[x][0] != m[y][0] and m[x][1] == m[y][1]
