# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def splitBST(self, root: TreeNode, V: int) -> List[TreeNode]:
        if root is None:
            return None, None
        else:
            if root.val == V:
                right = root.right
                root.right = None
                return root, right
            elif root.val < V:
                l, r = self.splitBST(root.right, V)
                root.right = l
                return root, r
            else: # root.val > V
                l, r = self.splitBST(root.left, V)
                root.left = r
                return l, root
