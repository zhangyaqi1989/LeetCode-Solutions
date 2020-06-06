# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 is None or l2 is None:
            return l1 or l2
        if l1.val < l2.val:
            head = l1
            rest = self.mergeTwoLists(l1.next, l2)
        else:
            head = l2
            rest = self.mergeTwoLists(l1, l2.next)
        head.next = rest
        return head