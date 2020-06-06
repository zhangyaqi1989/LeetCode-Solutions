# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
        to_delete = set(to_delete)
        nodes = []
        def dfs(node, parent, left=True):
            if node:
                if node.val in to_delete:
                    if parent:
                        if left:
                            parent.left = None
                        else:
                            parent.right = None
                    if node.left:
                        left = node.left
                        node.left = None
                        l = dfs(left, node)
                    if node.right:
                        right = node.right
                        node.right = None
                        dfs(right, node, False)
                else:
                    if parent is None or parent.val in to_delete:
                        nodes.append(node)
                    dfs(node.left, node)
                    dfs(node.right, node, False)
        dfs(root, None)
        return nodes
