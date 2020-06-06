# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def smallestFromLeaf(self, root: 'TreeNode') -> 'str':
        if not root:
            return ''
        else:
            if not root.left and not root.right:
                return chr(root.val + 97)
            elif not root.left or not root.right:
                return self.smallestFromLeaf(root.left or root.right) + chr(root.val + 97)
            left = self.smallestFromLeaf(root.left)
            right = self.smallestFromLeaf(root.right)
            if left < right:
                return left + chr((root.val + 97))
            else:
                return right + chr((root.val + 97))
