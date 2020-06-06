# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def generateTrees(self, n):
        """
        :type n: int
        :rtype: List[TreeNode]
        """
        if n == 0: return []
        def helper(l, r):
            if r < l:
                return [None]
            ans = []
            for i in range(l, r + 1):
                for left, right in itertools.product(helper(l, i - 1), helper(i + 1, r)):
                    root = TreeNode(i)
                    root.left, root.right = left, right
                    ans.append(root)
            return ans
        return helper(1, n)