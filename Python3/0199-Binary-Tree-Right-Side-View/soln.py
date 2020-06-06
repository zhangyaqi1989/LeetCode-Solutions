# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        sides = []
        queue = root is not None and collections.deque([root])
        while queue:
            size = len(queue)
            val = None
            for _ in range(size):
                node = queue.popleft()
                val = node.val
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            sides.append(val)
        return sides
