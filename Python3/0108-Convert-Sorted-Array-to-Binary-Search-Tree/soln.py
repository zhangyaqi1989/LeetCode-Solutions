# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        def build(i, j):
            if i == j:
                return None
            root_idx = (i + j - 1) // 2
            root = TreeNode(nums[root_idx])
            root.left = build(i, root_idx)
            root.right = build(root_idx + 1, j)
            return root
        return build(0, len(nums))