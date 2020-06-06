# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def plusOne(self, head: ListNode) -> ListNode:
        dummy = ListNode(1)
        dummy.next = head
        not_nine = dummy
        while head:
            if head.val != 9:
                not_nine = head
            head = head.next
        cur = not_nine.next
        while cur:
            cur.val = 0
            cur = cur.next
        if not_nine == dummy:
            return dummy
        else:
            not_nine.val += 1
            return dummy.next
