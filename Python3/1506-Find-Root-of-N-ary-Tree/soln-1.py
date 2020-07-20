"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""

class Solution:
    def findRoot(self, tree: List['Node']) -> 'Node':
        total = sum(node.val for node in tree)
        for node in tree:
            for child in node.children:
                total -= child.val
        for node in tree:
            if total == node.val:
                return node
