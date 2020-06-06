# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        queue = root and collections.deque([root])
        vals = []
        while queue:
            size = len(queue)
            row = []
            for _ in range(size):
                node = queue.popleft()
                row += [node.val]
                for nei in filter(None, (node.left, node.right)):
                    queue.append(nei)
            vals.append(row)
        return vals[::-1]