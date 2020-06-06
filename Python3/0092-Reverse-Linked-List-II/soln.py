class Solution:
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head
        cur = head
        left = dummy
        for _ in range(m - 1):
            left = cur
            cur = cur.next
        pre = None
        for _ in range(n - m + 1):
            temp = cur.next
            cur.next = pre
            pre = cur
            cur = temp
        left.next.next = cur
        left.next = pre
        return dummy.next