# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        queue = collections.deque([root])
        while queue:
            vals = []
            size = len(queue)
            for _ in range(size):
                node = queue.popleft()
                vals.append(node.val)
                queue.extend(filter(None, (node.left, node.right)))
        return vals[0]