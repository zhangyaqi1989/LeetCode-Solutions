# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        frontier = root and collections.deque([root])
        levels = []
        i = 0
        while frontier:
            level = []
            size = len(frontier)
            for _ in range(size):
                node = frontier.popleft()
                level.append(node.val)
                for child in filter(bool, (node.left, node.right)):
                    frontier.append(child)
            if i % 2:
                level = level[::-1]
            levels.append(level)
            i += 1
        return levels