# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root: return []
        counter = collections.Counter()
        def dfs(node):
            if node:
                counter[node.val] += 1
                dfs(node.left)
                dfs(node.right)
        dfs(root)
        max_cnt = max(counter.values() or [])
        return [k for k, v in counter.items() if v == max_cnt]