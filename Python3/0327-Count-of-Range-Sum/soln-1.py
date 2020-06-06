class Solution:
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        presum = [0] + list(itertools.accumulate(nums))
        def helper(lo, hi):
            mid = (hi + lo) >> 1
            if lo == mid:
                return 0
            cnt = helper(lo, mid) + helper(mid, hi)
            i = j = mid
            for left in presum[lo:mid]:
                while i < hi and presum[i] - left < lower:
                    i += 1
                while j < hi and presum[j] - left <= upper:
                    j += 1
                cnt += j - i
            presum[lo:hi] = sorted(presum[lo:hi])
            return cnt
        ans = helper(0, len(presum))
        return ans
