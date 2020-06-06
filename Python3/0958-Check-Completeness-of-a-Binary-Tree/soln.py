# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isCompleteTree(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        cur = 1
        queue = root and collections.deque([(root, 1)])
        while queue:
            node, i = queue.popleft()
            if i != cur:
                return False
            cur += 1
            if node.left:
                queue.append((node.left, i * 2))
            if node.right:
                queue.append((node.right, i * 2 + 1))
        return True
