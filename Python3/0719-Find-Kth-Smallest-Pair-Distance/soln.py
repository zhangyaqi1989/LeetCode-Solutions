class Solution:
    def smallestDistancePair(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # kth smallest distance
        nums = sorted(nums)
        lo, hi = 0, 1000000
        n = len(nums)
        while lo < hi:
            mid = (lo + hi) >> 1
            cnt = 0
            j = 0
            for i, num in enumerate(nums):
                while j < n and nums[j] - num <= mid:
                    j += 1
                cnt += j - i - 1
            # compute number of pairs that <= mid
            # how to choose if-else, think about cnt == mid
            if cnt < k: # mid is too small
                lo = mid + 1
            else:
                hi = mid
        return lo
