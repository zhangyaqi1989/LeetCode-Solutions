# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        # 1 -> 2 -> 3 -> 4
        # how to think recursively
        if head is None or head.next is None:
            return head
        second = head.next
        rest = self.swapPairs(second.next)
        second.next = head
        head.next = rest
        return second