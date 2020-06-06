# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def allPossibleFBT(self, N):
        """
        :type N: int
        :rtype: List[TreeNode]
        """
        N -= 1
        if N == 0:
            return [TreeNode(0)]
        ans = []
        for i in range(1, N, 2):
            for left, right in itertools.product(self.allPossibleFBT(i), self.allPossibleFBT(N - i)):
                root = TreeNode(0)
                root.left, root.right = left, right
                ans.append(root)
        return ans