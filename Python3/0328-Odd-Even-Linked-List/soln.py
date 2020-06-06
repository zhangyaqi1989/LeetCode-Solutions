# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # do it inplace
        if not head or not head.next:
            return head
        odd, even = head, head.next
        half = even
        cur = even.next
        is_odd = True
        while cur:
            if is_odd:
                odd.next = cur
                odd = odd.next
            else:
                even.next = cur
                even = even.next
            is_odd = not is_odd
            cur = cur.next
        odd.next = half
        even.next = None
        return head