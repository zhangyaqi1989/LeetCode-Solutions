class Solution:
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: TreeNode
        """
        if not nums:
            return None
        s = []
        for num in nums:
            node = TreeNode(num)
            while s and s[-1].val < num:
                node.left = s.pop()
            if s:
                s[-1].right = node
            s.append(node)
        return s[0]