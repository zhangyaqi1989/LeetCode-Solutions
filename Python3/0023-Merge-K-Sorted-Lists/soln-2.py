# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
from queue import PriorityQueue
class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        dummy = ListNode(0)
        cur = dummy
        q = PriorityQueue()
        for node in lists:
            if node:
                q.put((node.val, id(node), node))
        while q.qsize() > 0:
            node = q.get()[-1]
            cur.next = node
            cur = cur.next
            if cur.next:
                q.put((cur.next.val, id(cur.next), cur.next))
        return dummy.next