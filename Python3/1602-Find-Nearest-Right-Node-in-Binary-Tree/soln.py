# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findNearestRightNode(self, root: TreeNode, u: TreeNode) -> TreeNode:
        frontier = [root]
        while frontier:
            next_level = []
            for i, node in enumerate(frontier):
                if node.val == u.val:
                    return None if (i == len(frontier) - 1) else frontier[i + 1]
                if node.left is not None:
                    next_level.append(node.left)
                if node.right is not None:
                    next_level.append(node.right)
            frontier = next_level
        return None
