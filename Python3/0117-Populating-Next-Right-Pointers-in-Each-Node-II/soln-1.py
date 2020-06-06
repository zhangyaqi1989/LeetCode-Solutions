"""
# Definition for a Node.
class Node:
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if root is None:
            return
        frontier = collections.deque([root])
        while frontier:
            sz = len(frontier)
            for i in range(sz - 1):
                frontier[i].next = frontier[i + 1]
            for i in range(sz):
                node = frontier.popleft()
                for child in filter(None, (node.left, node.right)):
                    frontier.append(child)
        return root
