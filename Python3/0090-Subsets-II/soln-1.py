class Solution:
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ans = {()}
        nums.sort()
        for num in nums:
            ans |= {sub + (num, ) for sub in ans}
        return list(ans)