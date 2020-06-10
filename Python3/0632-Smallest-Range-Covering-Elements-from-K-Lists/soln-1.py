class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        pq = [(lst[0], 0, i) for i, lst in enumerate(nums)]
        heapq.heapify(pq)
        ans = [-1e5, 1e5]
        hi = max(lst[0] for lst in nums)
        while pq:
            lo, idx, lst_idx = heapq.heappop(pq)
            if hi - lo < ans[1] - ans[0]:
                ans = [lo, hi]
            if idx + 1 == len(nums[lst_idx]):
                return ans
            hi = max(hi, nums[lst_idx][idx + 1])
            heapq.heappush(pq, (nums[lst_idx][idx + 1], idx + 1, lst_idx))
