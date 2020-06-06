class Solution:
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        # [1, 1, 2]
        if not nums:
            return []
        nums = sorted(nums)
        ans = [[]]
        for num in nums:
            temp = []
            for perm in ans:
                for i in range((perm + [num]).index(num) + 1):
                    temp.append(perm[:i] + [num] + perm[i:])
            ans = temp
        return ans
