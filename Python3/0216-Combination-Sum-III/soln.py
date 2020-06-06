class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        nums = list(range(1, 10))
        res = []
        self.helper(nums, 0, k, n, [], res)
        return res
        
        
    def helper(self, nums, idx, k, target, combi, res):
        if target < 0 or len(combi) > k:
            return
        if len(combi) == k:
            if target == 0:
                res.append(combi)
            return
        if idx == len(nums):
            return
        for i in range(idx, len(nums)):
            self.helper(nums, i + 1, k, target - nums[i], combi + [nums[i]], res)