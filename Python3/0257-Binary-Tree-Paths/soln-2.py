# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:
        ans = []
        self.dfs(root, [], ans)
        return ans
        
    def dfs(self, node: TreeNode, path: List[int], ans: List[str]):
        if node:
            if not node.left and not node.right:
                path.append(node.val)
                ans.append('->'.join(map(str, path)))
                path.pop()
            else:
                path.append(node.val)
                for child in filter(None, [node.left, node.right]):
                    self.dfs(child, path, ans)
                path.pop()
