# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        ans = []
        stack = []
        i = 0
        vals = []
        while head:
            num = head.val
            vals.append(num)
            while stack and num > vals[stack[-1]]:
                ans[stack.pop()] = num
            stack.append(i)
            ans.append(0)
            i += 1
            head = head.next
        return ans
