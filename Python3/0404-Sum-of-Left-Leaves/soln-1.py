# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        def dfs(node, ans, is_left=False):
            if node is not None:
                if node.left is None and node.right is None:
                    if is_left:
                        ans[0] += node.val
                dfs(node.left, ans, True)
                dfs(node.right, ans)
        ans = [0]
        dfs(root, ans)
        return ans[0]
