# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def plusOne(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        non_nine, cur = None, head
        while cur:
            if cur.val != 9:
                non_nine = cur
            cur = cur.next
        if non_nine is None:
            dummy = ListNode(1)
            dummy.next = head
            non_nine = head
        else:
            dummy = head
            non_nine.val += 1
            non_nine = non_nine.next
        while non_nine:
            non_nine.val = 0
            non_nine = non_nine.next
        return dummy