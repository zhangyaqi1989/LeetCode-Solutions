# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        tail2 = list2
        while tail2.next is not None:
            tail2 = tail2.next
        cut_a = list1
        for _ in range(a - 1):
            cut_a = cut_a.next
        cut_b = cut_a
        for _ in range(b - a + 2):
            cut_b = cut_b.next
        cut_a.next = list2
        tail2.next = cut_b
        return list1
