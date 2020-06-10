"""
# Definition for a Node.
class Node:
    def __init__(self, val, next):
        self.val = val
        self.next = next
"""
class Solution:
    def insert(self, head, insertVal):
        """
        :type head: Node
        :type insertVal: int
        :rtype: Node
        """
        if not head:
            node = Node(insertVal, None)
            node.next = node
            return node
        pre = head
        cur = head.next
        while cur != head:
            if pre.val <= insertVal <= cur.val:
                break
            elif pre.val > cur.val and (insertVal < cur.val or insertVal > pre.val):
                break
            pre = pre.next
            cur = cur.next
        node = Node(insertVal, None)
        pre.next = node
        node.next = cur
        return head