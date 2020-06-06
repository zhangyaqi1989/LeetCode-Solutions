class Solution:
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        nums.sort()
        self.helper(nums, 0, [], res)
        return res
        
    def helper(self, nums, idx, sub, res):
        res.append(sub[:])
        if idx == len(nums):
            return
        for i in range(idx, len(nums)):
            if i > idx and nums[i] == nums[i - 1]:
                continue
            sub.append(nums[i])
            # self.helper(nums, i + 1, sub + [nums[i]], res)
            self.helper(nums, i + 1, sub, res)
            sub.pop()