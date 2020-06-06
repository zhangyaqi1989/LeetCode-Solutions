# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pseudoPalindromicPaths (self, root: TreeNode) -> int:
        counter = [0] * 10
        self.cnt = 0
        def dfs(node, counter):
            if node is not None:
                counter[node.val] += 1
                if node.left is None and node.right is None:
                    if sum(counter[i] % 2 for i in range(1, 10)) <= 1:
                        self.cnt += 1
                dfs(node.left, counter)
                dfs(node.right, counter)
                counter[node.val] -= 1
        dfs(root, counter)
        return self.cnt
