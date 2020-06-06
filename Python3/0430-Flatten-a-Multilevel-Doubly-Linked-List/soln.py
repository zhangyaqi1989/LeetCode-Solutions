"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""
class Solution(object):
    def flatten(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if not head:
            return None
        dummy = Node(0, None, None, None)
        self.cur = dummy
        self.pre = None
        def traverse(node):
            if not node: return
            child = node.child
            nxt = node.next
            self.cur.next = node
            node.child = None
            self.cur = self.cur.next
            if self.pre is not None:
                self.cur.prev = self.pre
            self.pre = node
            traverse(child)
            traverse(nxt)
        traverse(head)
        return dummy.next