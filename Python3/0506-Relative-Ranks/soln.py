class Solution:
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        ans = [None] * len(nums)
        for i, (j, num) in enumerate(sorted(enumerate(nums), key=lambda x : x[-1], reverse=True), 1):
            if i > 3:
                ans[j] = str(i)
            elif i == 3:
                ans[j] = "Bronze Medal"
            elif i == 2:
                ans[j] = "Silver Medal"
            else:
                ans[j] = "Gold Medal"
        return ans