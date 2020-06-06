class Solution:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if not nums:
            return []
        ans = [[]]
        for num in nums:
            ans += [item + [num] for item in ans]
        return ans