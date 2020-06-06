# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        def build(l, r):
            if r == l:
                return None
            mid = (l + r - 1) // 2
            root = TreeNode(nums[mid])
            root.left, root.right = build(l, mid), build(mid + 1, r)
            return root
        return build(0, len(nums))