# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        queue = collections.deque([root])
        res = []
        reverse = False
        while queue:
            size = len(queue)
            vals = []
            for _ in range(size):
                node = queue.popleft()
                vals.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            if reverse:
                res.append(vals[::-1])
            else:
                res.append(vals)
            reverse = not reverse
        return res