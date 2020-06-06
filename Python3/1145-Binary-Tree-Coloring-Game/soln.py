# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def btreeGameWinningMove(self, root: TreeNode, n: int, x: int) -> int:
        memo = {}
        tree = {}
        def dfs(node):
            if node is not None:
                tree[node.val] = node
                l = dfs(node.left)
                r = dfs(node.right)
                memo[node.val] = l + r + 1
                return l + r + 1
            else:
                return 0
        def is_child(node, x):
            if node is not None:
                if node.val == x:
                    return True
                return is_child(node.left, x) or is_child(node.right, x)
            else:
                return False
        dfs(root)
        red = memo[x]
        blue = max(memo[i] - is_child(tree[i], x) * red for i in range(1, n + 1) if i != x)
        return blue > n - blue
