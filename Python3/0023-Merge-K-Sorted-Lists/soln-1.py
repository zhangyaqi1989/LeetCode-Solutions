# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Pair:
    def __init__(self, node):
        self.val = node.val
        self.node = node
    def __lt__(self, other):
        return self.val < other.val

class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        heap = []
        for lst in lists:
            if lst:
                heapq.heappush(heap, Pair(lst))
        dummy = ListNode(-1)
        cur = dummy
        while heap:
            pair = heapq.heappop(heap)
            cur.next = pair.node
            cur = cur.next
            if pair.node.next:
                heapq.heappush(heap, Pair(pair.node.next))
        return dummy.next