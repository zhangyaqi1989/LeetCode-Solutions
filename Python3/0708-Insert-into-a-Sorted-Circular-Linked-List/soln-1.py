"""
# Definition for a Node.
class Node:
    def __init__(self, val, next):
        self.val = val
        self.next = next
"""
class Solution:
    def insert(self, head: 'Node', insertVal: int) -> 'Node':
        if head is None:
            return Node(insertVal, None)
        else:
            pre = head
            cur = head.next
            while cur != head:
                if pre.val <= insertVal <= cur.val or (pre.val > cur.val and (insertVal >= pre.val or insertVal <= cur.val)):
                    break
                pre = pre.next
                cur = cur.next
            node = Node(insertVal, None)
            node.next = cur
            pre.next = node
            return head
