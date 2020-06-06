class Solution:
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        diff_dict = {0 : -1} # key is the difference of ones and zeros
        ones, zeros = 0, 0
        ans = 0
        for i, num in enumerate(nums):
            if num == 0:
                zeros += 1
            else:
                ones += 1
            diff = ones - zeros
            if diff in diff_dict:
                ans = max(ans, i - diff_dict[diff])
            else:
                diff_dict[diff] = i
        return ans
