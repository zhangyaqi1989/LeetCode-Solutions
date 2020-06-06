class Solution:
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if not nums:
            return None
        max_index, max_val = max(enumerate(nums), key=operator.itemgetter(1))
        root = TreeNode(max_val)
        root.left, root.right = self.constructMaximumBinaryTree(nums[:max_index]), self.constructMaximumBinaryTree(nums[max_index + 1:])
        return root