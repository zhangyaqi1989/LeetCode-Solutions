# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        def toNum(head):
            ans = 0
            cur = head
            while cur:
                ans = ans * 10 + cur.val
                cur = cur.next
            return ans
        n = str(toNum(l1) + toNum(l2))
        head = cur = ListNode(1)
        for num in map(int, n):
            cur.next = ListNode(num)
            cur = cur.next
        return head.next