"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution(object):
    def postorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        if not root:
            return []
        stack = [root]
        vals = []
        while stack:
            node = stack.pop()
            vals.append(node.val)
            stack += [child for child in node.children]
        return vals[::-1]