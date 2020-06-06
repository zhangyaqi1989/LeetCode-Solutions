# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        if not root:
            return []
        res = []
        self.helper(root, [], res)
        return ['->'.join(map(str, item)) for item in res]
    
    def helper(self, node, path, res):
        if not node:
            return
        if not node.left and not node.right:
            res.append(path + [node.val])
            return
        self.helper(node.left, path + [node.val], res)
        self.helper(node.right, path + [node.val], res)