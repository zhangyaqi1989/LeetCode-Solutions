# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head:
            return False
        slow, fast = head, head.next
        while fast:
            if slow is fast:
                return True
            slow = slow.next
            fast = fast.next
            if fast:
                fast = fast.next
        return False
