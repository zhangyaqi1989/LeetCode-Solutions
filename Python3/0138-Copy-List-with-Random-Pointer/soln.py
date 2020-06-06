# Definition for singly-linked list with a random pointer.
# class RandomListNode(object):
#     def __init__(self, x):
#         self.label = x
#         self.next = None
#         self.random = None

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: RandomListNode
        :rtype: RandomListNode
        """
        if not head:
            return None
        cur = head
        visited = {}
        while cur:
            visited[cur] = RandomListNode(cur.label)
            cur = cur.next
        cur = head
        while cur:
            if cur.next:
                visited[cur].next = visited[cur.next]
            if cur.random:
                visited[cur].random = visited[cur.random]
            cur = cur.next
        return visited[head]