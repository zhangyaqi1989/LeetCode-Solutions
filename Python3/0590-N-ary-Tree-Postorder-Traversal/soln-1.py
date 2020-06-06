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
        stack = root and [root]
        vals = []
        while stack:
            node = stack.pop()
            vals.append(node.val)
            stack.extend(node.children)
        return vals[::-1]