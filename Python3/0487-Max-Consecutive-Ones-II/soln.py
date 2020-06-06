class Solution:
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # keep track of pre and cur length of concecutive 1s
        pre, cur, ans = -1, 0, 0 # why -1: for the case that nums are all 1s
        for num in nums:
            if num == 0:
                pre, cur = cur, 0
            else:
                cur += 1
            ans = max(ans, pre + 1 + cur)
        return ans