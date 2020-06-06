# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def widthOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        queue = collections.deque([(root, 1)])
        res = 0
        while queue:
            size = len(queue)
            first, second = None, None
            for _ in range(size):
                node, cnt = queue.popleft()
                if first is None:
                    first = cnt
                second = cnt
                if node.left:
                    queue.append((node.left, cnt * 2 ))
                if node.right:
                    queue.append((node.right, cnt * 2 + 1))
            res = max(res, second - first + 1)
        return res