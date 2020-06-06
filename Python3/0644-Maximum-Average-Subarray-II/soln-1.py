class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        # subarray length >= k
        # maximum average value
        def check(avg):
            cur, min_seen, prev = 0, 0, 0
            for i in range(k):
                cur += nums[i] - avg
            n = len(nums)
            if cur >= 0:
                return True
            for i in range(k, n):
                cur += nums[i] - avg
                prev += nums[i - k] - avg
                min_seen = min(min_seen, prev)
                if cur >= min_seen:
                    return True
            return cur >= min_seen
        lo, hi = min(nums), max(nums)
        while hi - lo > 0.00001:
            mid = (lo + hi) * 0.5
            if check(mid):
                lo = mid
            else:
                hi = mid
        return lo
