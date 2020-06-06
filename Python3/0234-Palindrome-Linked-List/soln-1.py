# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if not head or not head.next:
            return True
        slow, fast = head, head
        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
        if fast:
            slow = slow.next
        pre = None
        while slow:
            temp = slow.next
            slow.next = pre
            pre = slow
            slow = temp
        while pre and head:
            if pre.val != head.val:
                return False
            pre, head = pre.next, head.next
        return True