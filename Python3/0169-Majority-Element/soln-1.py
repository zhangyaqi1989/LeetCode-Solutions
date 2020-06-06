class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt, ans = 0, None
        for num in nums:
            if cnt == 0:
                ans = num
                cnt += 1
            else:
                cnt += 1 if ans == num else -1
        return ans