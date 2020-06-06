# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        pq = []
        cnt = itertools.count(0)
        for lst in lists:
            if lst is not None:
                pq.append((lst.val, next(cnt), lst.next))
        heapq.heapify(pq)
        dummy = ListNode(0)
        cur = dummy
        while pq:
            val, _, node = heapq.heappop(pq)
            cur.next = ListNode(val)
            cur = cur.next
            if node is not None:
                heapq.heappush(pq, (node.val, next(cnt), node.next))
        return dummy.next