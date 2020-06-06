# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        # no value is greater than node
        self.ans = 0
        def dfs(node, mx):
            if node is not None:
                if node.val >= mx:
                    self.ans += 1
                dfs(node.left, max(mx, node.val))
                dfs(node.right, max(mx, node.val))
        dfs(root, -math.inf)
        return self.ans
