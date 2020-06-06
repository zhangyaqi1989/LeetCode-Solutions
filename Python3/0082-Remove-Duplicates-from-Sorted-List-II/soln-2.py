# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head is None:
            return head
        dummy = ListNode(0)
        dummy.next = head
        cur = head
        cnt = 0
        node = head
        nxt = dummy
        while cur:
            if cur.val == node.val:
                cnt += 1
            else:
                if cnt == 1:
                    nxt.next = node
                    nxt = nxt.next
                cnt = 1
                node = cur
            cur = cur.next
        if cnt == 1:
            nxt.next = node
            node.next = None
        else:
            nxt.next = None
        return dummy.next
