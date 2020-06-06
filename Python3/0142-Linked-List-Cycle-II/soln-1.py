# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        try:
            fast = head.next.next
            slow = head.next
            while fast is not slow:
                fast = fast.next.next
                slow = slow.next
            slow = head
            while slow is not fast:
                slow = slow.next
                fast = fast.next
            return slow
        except:
            return None
