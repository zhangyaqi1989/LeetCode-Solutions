class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def first(lo, hi, valid):
            while lo < hi:
                mid = lo + (hi - lo) // 2
                if valid(mid):
                    hi = mid
                else:
                    lo = mid + 1
            return lo
        lo = first(0, len(nums) - 1, lambda x : nums[x] >= target)
        if not (0 <= lo < len(nums) and nums[lo] == target):
            return -1, -1
        hi = first(0, len(nums), lambda x : nums[x] > target)
        return lo, hi - 1
