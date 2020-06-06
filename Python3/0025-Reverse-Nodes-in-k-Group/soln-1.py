# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        pre = cur = head
        cnt = 0
        while cur is not None:
            pre = cur
            cur = cur.next
            cnt += 1
            if cnt == k:
                break
        else:
            return head
        pre.next = None
        first = self.reverse(head)
        head.next = self.reverseKGroup(cur, k)
        return pre
    
    def reverse(self, head):
        if head is None or head.next is None:
            return head
        nxt = head.next
        new_head = self.reverse(head.next)
        nxt.next = head
        head.next = None
        return new_head
        
