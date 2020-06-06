# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        p1, p2, carry = l1, l2, 0
        dummy = cur = ListNode(0)
        while p1 or p2 or carry:
            val1 = p1.val if p1 else 0
            val2 = p2.val if p2 else 0
            carry, val = divmod(val1 + val2 + carry, 10)
            cur.next = ListNode(val)
            cur = cur.next
            p1 = p1.next if p1 else None
            p2 = p2.next if p2 else None
        return dummy.next