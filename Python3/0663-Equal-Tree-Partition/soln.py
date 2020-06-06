# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def checkEqualTree(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        sums = collections.defaultdict(list)
        def compute_sum(node):
            if not node:
                return 0
            else:
                ans = node.val + compute_sum(node.left) + compute_sum(node.right)
                sums[ans].append(node)
                return ans
        total = compute_sum(root)
        if total == 0:
            return len(sums[0]) > 1
        else:
            return total % 2 == 0 and total // 2 in sums
