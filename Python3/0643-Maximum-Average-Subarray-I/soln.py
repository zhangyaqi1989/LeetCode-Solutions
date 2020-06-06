class Solution:
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        acc = sum(nums[:k])
        mx = acc
        for i in range(k, len(nums)):
            acc += nums[i]
            acc -= nums[i - k]
            if acc > mx:
                mx = acc
        return mx / k