"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []
"""

class Solution:
    def diameter(self, root: 'Node') -> int:
        """
        :type root: 'Node'
        :rtype: int
        """
        # heights
        self.longest_path = 0
        def postorder(node):
            if node is None:
                return 0
            heights = [postorder(child) for child in node.children]
            first_two = list(heapq.nlargest(2, heights))
            self.longest_path = max(self.longest_path, sum(first_two))
            return max(heights or [0]) + 1
        postorder(root)
        return self.longest_path
