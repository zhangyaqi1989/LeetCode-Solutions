# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minCameraCover(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        LEAF, PARENT_OF_LEAF, COVERED = 0, 1, 2
        cameras = 0
        def dfs(node):
            nonlocal cameras
            if node is None:
                return COVERED
            elif node.left is None and node.right is None:
                return LEAF
            left, right = dfs(node.left), dfs(node.right)
            if left == LEAF or right == LEAF:
                cameras += 1
                return PARENT_OF_LEAF
            if left == PARENT_OF_LEAF or right == PARENT_OF_LEAF:
                return COVERED
            return LEAF
        return (dfs(root) == LEAF) + cameras
