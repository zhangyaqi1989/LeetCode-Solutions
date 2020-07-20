# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getLonelyNodes(self, root: TreeNode) -> List[int]:
        def dfs(node):
            if node is not None:
                if node.left is None and node.right is not None:
                    ans.append(node.right.val)
                if node.left is not None and node.right is None:
                    ans.append(node.left.val)
                dfs(node.left)
                dfs(node.right)
        ans = []
        dfs(root)
        return ans
