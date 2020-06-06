# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, target: int) -> int:
        seen = collections.Counter()
        seen[0] = 1
        self.cnt = 0
        def dfs(node, acc):
            if node:
                acc += node.val
                self.cnt += seen[acc - target]
                seen[acc] += 1
                dfs(node.left, acc)
                dfs(node.right, acc)
                seen[acc] -= 1
        dfs(root, 0)
        return self.cnt
