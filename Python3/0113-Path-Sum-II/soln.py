# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root, target):
        """
        :type root: TreeNode
        :type target: int
        :rtype: List[List[int]]
        """
        ans = []
        self.helper(root, [], target, ans)
        return ans
        
    def helper(self, node, path, target, ans):
        if not node:
            return
        if not node.left and not node.right and node.val == target:
            ans.append(path + [node.val])
        self.helper(node.left, path + [node.val], target - node.val, ans)
        self.helper(node.right, path + [node.val], target - node.val, ans)