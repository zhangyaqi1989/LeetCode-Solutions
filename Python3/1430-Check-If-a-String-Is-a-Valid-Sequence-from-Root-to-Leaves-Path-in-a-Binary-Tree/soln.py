# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidSequence(self, root: TreeNode, arr: List[int]) -> bool:
        def dfs(idx, node):
            if idx == len(arr) - 1:
                return node is not None and node.val == arr[-1] and node.left is None and node.right is None
            else:
                if node is not None:
                    return node.val == arr[idx] and (dfs(idx + 1, node.left) or dfs(idx + 1, node.right))
                else:
                    return False
        return dfs(0, root)
