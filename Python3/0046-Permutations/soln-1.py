class Solution:
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # can build permutation iteratively
        if not nums: return []
        ans = [[]]
        for num in nums:
            ans = [item[:i] + [num] + item[i:] for item in ans for i in range(len(item) + 1)]
        return ans