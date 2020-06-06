"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: Node
        :rtype: int
        """
        if not root:
            return 0
        queue = collections.deque([root])
        level = 0
        while queue:
            size = len(queue)
            level += 1
            for _ in range(size):
                node = queue.popleft()
                for child in node.children:
                    queue.append(child)
        return level