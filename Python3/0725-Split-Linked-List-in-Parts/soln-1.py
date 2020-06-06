# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def splitListToParts(self, root: ListNode, k: int) -> List[ListNode]:
        cur = root
        cnt = 0
        while cur is not None:
            cnt += 1
            cur = cur.next
        ans = []
        q, r = divmod(cnt, k)
        cnt = 0
        cur = root
        for i in range(k):
            ans.append(cur)
            if cur is None:
                continue
            if i < r:
                moves = q + 1
            else:
                moves = q
            for _ in range(moves - 1):
                cur = cur.next
            temp = cur.next
            cur.next = None
            cur = temp
        return ans
