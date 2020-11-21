# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def correctBinaryTree(self, root: TreeNode) -> TreeNode:
        level = {root}
        parents = {}
        while level:
            next_level = set()
            for node in level:
                if node.left is not None:
                    next_level.add(node.left)
                    parents[node.left] = (node, 0)
                if node.right is not None:
                    if node.right in level:
                        parent, lr = parents[node]
                        if lr == 0:
                            parent.left = None
                        else:
                            parent.right = None
                        return root
                    next_level.add(node.right)
                    parents[node.right] = (node, 1)
            level = next_level
