# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        def helper(pa, pb, ia, ib):
            if pb <= pa:
                return None
            root_val = preorder[pa]
            root = TreeNode(root_val)
            idx = inorder.index(root_val, ia)
            root.left, root.right = helper(pa + 1, pa + 1 + idx - ia, ia, idx), helper(pa + 1 + idx - ia, pb, idx + 1, ib)
            return root
        return helper(0, len(preorder), 0, len(inorder))