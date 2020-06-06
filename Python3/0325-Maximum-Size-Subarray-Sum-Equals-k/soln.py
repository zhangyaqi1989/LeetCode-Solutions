class Solution:
    def maxSubArrayLen(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # find max length subarray
        d = {0 : -1}
        ans = 0
        acc = 0
        for i, num in enumerate(nums):
            acc += num
            if acc - k in d:
                ans = max(ans, i - d[acc - k])
            if acc not in d:
                d[acc] = i
        return ans