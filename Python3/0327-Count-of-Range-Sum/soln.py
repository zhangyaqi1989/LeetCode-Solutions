class Solution:
    def countRangeSum(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: int
        """
        accs = [0] + list(itertools.accumulate(nums))
        def helper(lo, hi):
            mid = (lo + hi) >> 1
            if lo == mid:
                return 0
            cnt = helper(lo, mid) + helper(mid, hi)
            i = j = mid
            for left in accs[lo:mid]:
                while i < hi and accs[i] - left < lower: i += 1
                while j < hi and accs[j] - left <= upper: j += 1
                cnt += j - i
            accs[lo:hi] = sorted(accs[lo:hi])
            return cnt
        return helper(0, len(accs))
