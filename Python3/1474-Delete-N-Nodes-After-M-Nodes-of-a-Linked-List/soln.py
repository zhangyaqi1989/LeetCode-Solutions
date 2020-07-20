# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteNodes(self, head: ListNode, m: int, n: int) -> ListNode:
        cur = head
        while cur is not None:
            for _ in range(m - 1):
                if cur is not None:
                    cur = cur.next
            temp = cur
            for _ in range(n + 1):
                if temp is not None:
                    temp = temp.next
            if cur is not None:
                cur.next = temp
                cur = temp
        return head
