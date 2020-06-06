# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        mod = 1000000007
        self.ans = 0
        def dfs(node, acc):
            if node is not None:
                acc = acc * 2 + node.val
                if node.left is None and node.right is None:
                    self.ans += acc
                dfs(node.left, acc)
                dfs(node.right, acc)
        dfs(root, 0)
        return self.ans % mod
