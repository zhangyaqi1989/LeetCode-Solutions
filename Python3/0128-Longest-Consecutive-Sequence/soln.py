class Solution:
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # starts to search from the minimum num
        s = set(nums)
        res = 0
        for num in nums:
            if num - 1 not in s:
                cnt = 1
                temp = num + 1
                while temp in s:
                    cnt += 1
                    temp += 1
                res = max(res, cnt)
        return res