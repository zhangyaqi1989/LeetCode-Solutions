"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""
class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        def post(node):
            if node:
                post(node.next)
                post(node.child)
                node.next = self.suc
                node.child = None
                if self.suc:
                    self.suc.prev = node
                self.suc = node
        self.suc = None
        post(head)
        return head
