# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """
        if not head or not head.next or not head.next.next:
            return
        pre = None
        slow, fast = head, head
        while fast and fast.next:
            pre = slow
            slow = slow.next
            fast = fast.next.next
        pre.next = None
        
        pre = None
        while slow:
            temp = slow.next
            slow.next = pre
            pre = slow
            slow = temp
        second = pre
        i = 0
        cur = dummy = ListNode(0)
        while second and head:
            if i % 2 == 0:
                cur.next = head
                head = head.next
            else:
                cur.next = second
                second = second.next
            i += 1
            cur = cur.next
        cur.next = second or head