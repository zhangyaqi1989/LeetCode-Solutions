# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Pair:
    def __init__(self, val, node):
        self.val = val
        self.node = node
        
    def __lt__(self, other):
        return self.val < other.val

class Solution:
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        queue = []
        for node in lists:
            if node:
                heapq.heappush(queue, Pair(node.val, node))
        head = cur = ListNode(0)
        while queue:
            pair = heapq.heappop(queue)
            val, node = pair.val, pair.node
            cur.next = ListNode(val)
            cur = cur.next
            if node.next:
                heapq.heappush(queue, Pair(node.next.val, node.next))
        return head.next