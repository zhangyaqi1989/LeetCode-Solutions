# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        cur = dummy = ListNode(0)
        num, cnt = None, 0
        pre = None
        while head:
            if head.val == num:
                cnt += 1
            else:
                if num is not None and cnt == 1:
                    cur.next = pre
                    cur = cur.next
                num = head.val
                cnt = 1
            pre = head
            head = head.next
        if num is not None and cnt == 1:
            cur.next = pre
            cur = cur.next
        else:
            cur.next = None
        return dummy.next
