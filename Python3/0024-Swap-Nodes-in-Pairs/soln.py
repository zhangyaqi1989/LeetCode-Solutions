# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # pre->a->b->b.next ==> pre->b->a->b.next
        dummy = ListNode(1)
        dummy.next = head
        pre = dummy
        while pre.next and pre.next.next:
            a = pre.next
            b = pre.next.next
            pre.next, a.next, b.next = b, b.next, a
            pre = a
        return dummy.next