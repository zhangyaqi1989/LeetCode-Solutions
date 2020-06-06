class Solution:
    def threeSumSmaller(self, nums: List[int], target: int) -> int:
        nums.sort()
        ans = 0
        n = len(nums)
        for i in range(n - 2):
            lo, hi = i + 1, n - 1
            while lo < hi:
                s = nums[i] + nums[lo] + nums[hi]
                if s < target:
                    ans += hi - lo # for this lo, all [lo + 1, hi] is valid
                    lo += 1
                else:
                    # s >= target
                    hi -= 1
        return ans
