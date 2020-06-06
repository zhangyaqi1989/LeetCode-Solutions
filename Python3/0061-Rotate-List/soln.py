# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        n = 0
        cur = head
        while cur:
            n += 1
            cur = cur.next
        if n == 0:
            return head
        k %= n
        if k == 0:
            return head
        slow, fast = head, head
        for _ in range(k):
            fast = fast.next
        while fast.next:
            fast = fast.next
            slow = slow.next
        fast.next = head
        new_head = slow.next
        slow.next = None
        return new_head
