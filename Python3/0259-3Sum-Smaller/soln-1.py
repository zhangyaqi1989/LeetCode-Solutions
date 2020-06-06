class Solution:
    def threeSumSmaller(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # solve this in n^2
        nums.sort()
        cnt = 0
        for i in range(len(nums) - 2):
            l, r = i + 1, len(nums) - 1
            while l < r:
                s = nums[i] + nums[l] + nums[r]
                if s < target:
                    cnt += r - l
                    l += 1
                else:
                    r -= 1
        return cnt