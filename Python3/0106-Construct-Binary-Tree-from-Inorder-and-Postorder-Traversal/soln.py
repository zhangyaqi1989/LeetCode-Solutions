# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder, postorder):
        """
        :type inorder: List[int]
        :type postorder: List[int]
        :rtype: TreeNode
        """
        # inorder = [9,3,15,20,7]
        # postorder = [9,15,7,20,3]
        return self.helper(inorder, 0, len(inorder), postorder, 0, len(postorder))
        
    def helper(self, inorder, i, j, postorder, p, q):
        if i == j:
            return None
        root_val = postorder[q - 1]
        root = TreeNode(root_val)
        idx = inorder.index(root_val, i)
        root.left = self.helper(inorder, i, idx, postorder, p, p + idx - i)
        root.right = self.helper(inorder, idx + 1, j, postorder, p + idx - i, q - 1)
        return root