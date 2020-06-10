class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        lo, hi = -100000, 100000
        pq = [(lst[0], i, 1) for i, lst in enumerate(nums)]
        heapq.heapify(pq)
        right = max(lst[0] for lst in nums)
        while len(pq) == len(nums):
            mn, idx, nxt = heapq.heappop(pq)
            if right - mn < hi - lo:
                lo = mn
                hi = right
            if nxt < len(nums[idx]):
                right = max(right, nums[idx][nxt])
                heapq.heappush(pq, (nums[idx][nxt], idx, nxt + 1))
        return [lo, hi]
