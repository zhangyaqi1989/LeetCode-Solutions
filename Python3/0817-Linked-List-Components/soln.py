# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def numComponents(self, head, G):
        """
        :type head: ListNode
        :type G: List[int]
        :rtype: int
        """
        G = set(G)
        enter = False
        cnt = 0
        cur = head
        while cur:
            if cur.val in G:
                if not enter:
                    enter = True
                    cnt += 1
            else:
                if enter:
                    enter = False
            cur = cur.next
        return cnt