class Solution:
    def validSubarrays(self, nums: List[int]) -> int:
        cnt = 0
        stack = []
        for i, num in enumerate(nums):
            while stack and num < nums[stack[-1]]:
                cnt += i - stack.pop()
            stack.append(i)
        return cnt + sum(len(nums) - i for i in stack)
