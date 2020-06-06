class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        queue = collections.deque()
        res = []
        for idx, num in enumerate(nums):
            while queue and num > nums[queue[-1]]:
                queue.pop()
            queue.append(idx)
            if idx - queue[0] >= k:
                queue.popleft()
            if idx >= k - 1:
                res.append(nums[queue[0]])
        return res