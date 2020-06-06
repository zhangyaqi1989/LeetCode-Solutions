class Solution:
    def medianSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[float]
        """
        def median(array):
            "Compute median of array."
            n = len(array)
            if n & 1 == 1:
                return 1.0 * array[n // 2]
            else:
                return 0.5 * (array[n // 2 - 1] + array[n // 2])
        window = sorted(nums[:k])
        ans = []
        for i in range(len(nums) - k):
            ans.append(median(window))
            window.remove(nums[i])
            bisect.insort(window, nums[i + k])
        ans.append(median(window))
        return ans
