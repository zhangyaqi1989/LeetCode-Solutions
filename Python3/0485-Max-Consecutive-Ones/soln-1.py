class Solution:
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        ans = 0
        for j, num in enumerate(nums + [0]):
            if num == 0:
                ans = max(ans, j - i)
                i = j + 1
        return ans