# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: TreeNode) -> bool:
        level_num = 0
        frontier = [root]
        while frontier:
            if level_num % 2 == 0:
                if not all(node.val % 2 == 1 for node in frontier):
                    return False
                if not all(frontier[i].val < frontier[i + 1].val for i in range(len(frontier) - 1)):
                    return False
            else:
                if not all(node.val % 2 == 0 for node in frontier):
                    return False
                if not all(frontier[i].val > frontier[i + 1].val for i in range(len(frontier) - 1)):
                    return False
            next_level = []
            for node in frontier:
                if node.left is not None:
                    next_level.append(node.left)
                if node.right is not None:
                    next_level.append(node.right)
            level_num += 1
            frontier = next_level
        return True
