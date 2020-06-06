# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def verticalOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
            return []
        res = collections.defaultdict(list) # col -> (row, val)
        queue = collections.deque([(0, 0, root)])
        while queue:
            size = len(queue)
            for _ in range(size):
                r, c, node = queue.popleft()
                res[c].append((r, node.val))
                if node.left:
                    queue.append((r + 1, c - 1, node.left))
                if node.right:
                    queue.append((r + 1, c + 1, node.right))
        return [[val for _, val in res[col]] for col in sorted(res.keys())]