# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def splitListToParts(self, root, k):
        """
        :type root: ListNode
        :type k: int
        :rtype: List[ListNode]
        """
        cur = root
        cnt = 0
        while cur:
            cnt += 1
            cur = cur.next
        q, r = divmod(cnt, k)
        ans = []
        cur = root
        i = 0
        while i < k:
            num = (q + 1) if i < r else q
            ans.append(cur)
            pre = None
            for _ in range(num):
                pre = cur
                cur = cur.next
            if pre: pre.next = None
            i += 1
        return ans