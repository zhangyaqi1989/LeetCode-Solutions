# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if not preorder:
            return None
        root_val = preorder[0]
        idx = inorder.index(root_val)
        root = TreeNode(root_val)
        root.left = self.buildTree(preorder[1:1+idx], inorder[:idx])
        root.right = self.buildTree(preorder[1+idx:], inorder[idx+1:])
        return root