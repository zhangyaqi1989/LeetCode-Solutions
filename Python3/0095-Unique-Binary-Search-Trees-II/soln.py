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
        if n == 0:
            return []
        def build(i, j):
            if i == j:
                return [TreeNode(i)]
            if i >= j:
                return [None]
            res = []
            for k in range(i, j + 1):
                for left, right in itertools.product(build(i, k - 1), build(k + 1, j)):
                    root = TreeNode(k)
                    root.left = left
                    root.right = right
                    res.append(root)
            return res
        return build(1, n)