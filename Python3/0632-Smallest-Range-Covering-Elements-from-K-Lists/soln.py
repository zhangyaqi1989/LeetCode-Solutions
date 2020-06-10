class Solution:
    def smallestRange(self, nums):
        """
        :type nums: List[List[int]]
        :rtype: List[int]
        """
        heap = [(lst[0], 0, i) for i, lst in enumerate(nums)]
        heapq.heapify(heap)
        ans = -1e5, 1e5
        right = max(lst[0] for lst in nums)
        while heap:
            left, j, lst_idx = heapq.heappop(heap)
            if right - left < ans[1] - ans[0]:
                ans = left, right
            if j + 1 == len(nums[lst_idx]):
                return ans
            right = max(right, nums[lst_idx][j + 1])
            heapq.heappush(heap, (nums[lst_idx][j + 1], j + 1, lst_idx))