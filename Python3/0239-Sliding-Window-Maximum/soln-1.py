class Solution:
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        pq = []
        mxs = []
        for i, num in enumerate(nums):
            heapq.heappush(pq, (-num, i))
            if i >= k - 1:
                while pq:
                    val, idx = pq[0]
                    if i - idx >= k:
                        heapq.heappop(pq)
                    else:
                        mxs.append(-val)
                        break
        return mxs