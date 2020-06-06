"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: Node
        :rtype: List[List[int]]
        """
        if not root:
            return []
        res = []
        queue = collections.deque([root])
        while queue:
            size = len(queue)
            vals = []
            for _ in range(size):
                node = queue.popleft()
                vals.append(node.val)
                for child in node.children:
                    queue.append(child)
            res.append(vals)
        return res