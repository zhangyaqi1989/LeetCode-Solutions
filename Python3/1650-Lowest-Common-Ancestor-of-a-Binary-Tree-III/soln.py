"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""

class Solution:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        seen = set()
        while p is not None:
            seen.add(p)
            p = p.parent
        while q is not None:
            if q in seen:
                return q
            q = q.parent
        return None
