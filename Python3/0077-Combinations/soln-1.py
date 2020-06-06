class Solution:
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        nums, ans = list(range(1, n + 1)), []
        self.helper(nums, 0, [], ans, k)
        return ans
    def helper(self, nums, idx, combo, ans, k):
        if len(combo) == k:
            ans.append(combo)
        else:
            for i in range(idx, len(nums)):
                self.helper(nums, i + 1, combo + [nums[i]], ans, k)