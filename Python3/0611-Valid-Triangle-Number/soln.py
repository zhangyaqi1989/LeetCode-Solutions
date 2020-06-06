class Solution:
    def triangleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # valid triangle sum of two smaller nums > largest num
        nums.sort(reverse=True)
        cnt, n = 0, len(nums)
        for i in range(n - 2):
            # if i > 0 and nums[i] == nums[i - 1]:
            #     continue
            l, r = i + 1, n - 1
            while l < r:
                if nums[l] + nums[r] > nums[i]:
                    cnt += r - l
                    l += 1
                else:
                    r -= 1
        return cnt