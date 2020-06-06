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
        cur = head
        count = 0
        while cur is not None and count != k:
            count += 1
            cur = cur.next
        if count == k:
            cur = self.reverseKGroup(cur, k)
            while count > 0:
                count -= 1
                temp = head.next
                head.next = cur
                cur = head
                head = temp
            head = cur
        return head