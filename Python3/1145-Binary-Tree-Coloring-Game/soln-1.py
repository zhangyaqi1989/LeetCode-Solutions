# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def btreeGameWinningMove(self, root: TreeNode, n: int, x: int) -> bool:
        children = [0, 0]
        def dfs(node):
            if node is not None:
                l, r = dfs(node.left), dfs(node.right)
                if node.val == x:
                    children[0] = l
                    children[1] = r
                return l + r + 1
            else:
                return 0
        dfs(root)
        return max(max(children), n - sum(children) - 1) > (n / 2)
