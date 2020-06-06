# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def bstFromPreorder(self, preorder: List[int]) -> TreeNode:
        def helper(lo, hi):
            if hi <= lo:
                return None
            root_val = preorder[lo]
            idx = lo + 1
            while idx < hi:
                if preorder[idx] > root_val:
                    break
                idx += 1
            root = TreeNode(root_val)
            root.left = helper(lo + 1, idx)
            root.right = helper(idx, hi)
            return root
        return helper(0, len(preorder))
