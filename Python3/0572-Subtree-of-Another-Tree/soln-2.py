# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import hashlib
class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        def hash_(x):
            x = x.encode('utf-8')
            m = hashlib.sha256()
            m.update(x)
            return m.hexdigest()
        def encode(node):
            if node is not None:
                l_hash = encode(node.left)
                r_hash = encode(node.right)
                h = hash_(l_hash + str(node.val) + r_hash)
                node.hash = h
                return h
            else:
                return "#"
        encode(s)
        encode(t)
        def dfs(node, target):
            if node is not None:
                return node.hash == target.hash or dfs(node.left, target) or dfs(node.right, target)
            return False
        return dfs(s, t)
