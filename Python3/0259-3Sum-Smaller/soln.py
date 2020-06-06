class Solution:
    def threeSumSmaller(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        cnt, n = 0, len(nums)
        for i in range(n - 2):
            l, r = i + 1, n - 1
            while l < r:
                sm = nums[i] + nums[l] + nums[r]
                if sm < target:
                    cnt += r - l
                    l += 1
                else:
                    r -= 1
        return cnt