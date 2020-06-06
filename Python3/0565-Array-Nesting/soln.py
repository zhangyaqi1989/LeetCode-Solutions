class Solution:
    def arrayNesting(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        visited = [0] * len(nums)
        ans = 0
        for i in nums:
            count, j = 0, i
            while not visited[j]:
                visited[j], count, j = 1, count + 1, nums[j]
            ans = max(ans, count)
        return ans