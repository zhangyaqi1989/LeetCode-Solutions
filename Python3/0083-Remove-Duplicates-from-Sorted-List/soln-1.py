# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        cur = head;
        pre = head;
        while cur:
            while cur.next and cur.val == cur.next.val:
                cur = cur.next
            pre.next = cur.next
            pre = pre.next
            cur = cur.next
        return head
