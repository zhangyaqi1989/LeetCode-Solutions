"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""

class Solution:
    def cloneTree(self, root: 'Node') -> 'Node':
        self.new_root = None
        def dfs(node, parent):
            if node is not None:
                new_node = Node(node.val)
                if parent is not None:
                    parent.children.append(new_node)
                else:
                    self.new_root = new_node
                for child in node.children:
                    dfs(child, new_node)
        dfs(root, None)
        return self.new_root
