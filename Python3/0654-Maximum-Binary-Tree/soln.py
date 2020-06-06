class Solution:
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        return self.helper(nums, 0, len(nums))
        
    def helper(self, nums, l, r):
        if l == r:
            return None
        max_idx = l
        max_ele = nums[l]
        i = l
        while i < r:
            if nums[i] > max_ele:
                max_ele = nums[i]
                max_idx = i
            i += 1
        root = TreeNode(nums[max_idx])
        root.left = self.helper(nums, l, max_idx)
        root.right = self.helper(nums, max_idx + 1, r)
        return root