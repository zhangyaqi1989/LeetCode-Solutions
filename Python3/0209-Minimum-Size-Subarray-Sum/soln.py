class Solution:
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        # n positive integer
        lo = acc = 0
        ans = math.inf
        for hi, num in enumerate(nums):
            acc += num
            if acc >= s:
                while lo < hi and acc - nums[lo] >= s:
                    acc -= nums[lo]
                    lo += 1
                ans = min(ans, hi - lo + 1)
        return 0 if ans == math.inf else ans
