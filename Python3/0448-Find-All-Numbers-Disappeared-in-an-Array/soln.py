class Solution:
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # [4,3,2,7,8,2,3,1] map: num to num - 1 idx
        ans = []
        for num in nums:
            nums[abs(num) - 1] = -abs(nums[abs(num) - 1])
        for i in range(1, len(nums) + 1):
            if nums[i - 1] > 0:
                ans.append(i)
        return ans