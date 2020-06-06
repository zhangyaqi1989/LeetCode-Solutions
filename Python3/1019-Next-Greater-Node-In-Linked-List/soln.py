# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        cur = head
        cnt = 0
        nums = []
        while cur:
            cnt += 1
            nums.append(cur.val)
            cur = cur.next
        ans = [0] * cnt
        stack = []
        for i, num in enumerate(nums):
            while stack and num > nums[stack[-1]]:
                ans[stack.pop()] = num
            stack.append(i)
        return ans
        
        
