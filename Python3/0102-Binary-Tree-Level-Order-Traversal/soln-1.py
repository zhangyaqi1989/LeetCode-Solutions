# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        queue = collections.deque([root])
        vals = []
        while queue:
            size = len(queue)
            row = []
            for _ in range(size):
                node = queue.popleft()
                row.append(node.val)
                queue.extend(filter(None, (node.left, node.right)))
            vals.append(row)
        return vals