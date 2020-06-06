# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isUnivalTree(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def dfs(node, val=None):
            if node is not None:
                if val is None:
                    val = node.val
                else:
                    if node.val != val:
                        return False
                return dfs(node.left, val) and dfs(node.right, val)
            else:
                return True
        return dfs(root)
