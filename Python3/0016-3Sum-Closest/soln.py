class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        min_diff = float('inf')
        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]: continue
            l, r = i + 1, len(nums) - 1
            while l < r:
                diff = nums[i] + nums[l] + nums[r] - target
                if diff == 0: return target
                if abs(diff) < abs(min_diff):
                    min_diff = diff
                if diff > 0:
                    r -= 1
                else:
                    l += 1
        return target + min_diff