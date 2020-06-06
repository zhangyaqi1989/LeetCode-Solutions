# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = cur = ListNode(0)
        p1, p2 = l1, l2
        while p1 and p2:
            if p1.val <= p2.val:
                val = p1.val
                p1 = p1.next
            else:
                val = p2.val
                p2 = p2.next
            cur.next = ListNode(val)
            cur = cur.next
        cur.next = p1 or p2
        return head.next