# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        dic = collections.defaultdict(list)
        def traverse(node):
            if not node:
                return 0
            left = traverse(node.left)
            right = traverse(node.right)
            lev = max(left, right) + 1
            dic[lev] += [node.val]
            return lev
        traverse(root)
        return [dic[lev] for lev in range(1, len(dic) + 1)]