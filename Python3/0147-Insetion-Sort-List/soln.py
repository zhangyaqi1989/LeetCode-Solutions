# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        dummy = cur = ListNode(-math.inf)
        while head:
            cur = dummy
            while cur.next and cur.next.val <= head.val:
                cur = cur.next
            nxt = head.next
            head.next = cur.next
            cur.next = head
            head = nxt
        return dummy.next
