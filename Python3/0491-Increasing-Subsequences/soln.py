class Solution:
    def findSubsequences(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # there are duplicates
        res = set()
        self.helper(nums, 0, (), res)
        return list(res)
    
    def helper(self, nums, idx, sub, res):
        if len(sub) > 1:
            res.add(sub)
        if idx == len(nums):
            return
        for i in range(idx, len(nums)):
            if not sub or nums[i] >= sub[-1]:
                self.helper(nums, i + 1, sub + (nums[i],), res)