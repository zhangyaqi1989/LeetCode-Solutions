"""
# Definition for a Node.
class Node:
    def __init__(self, val, left, right, parent):
        self.val = val
        self.left = left
        self.right = right
        self.parent = parent
"""
class Solution:
    def inorderSuccessor(self, node: 'Node') -> 'Node':
        if not node:
            return None
        if node.right:
            cur = node.right
            while cur.left:
                cur = cur.left
            return cur
        else:
            ans = node.parent
            while ans and ans.val < node.val:
                ans = ans.parent
            return ans
