class Solution:
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mn = mx = ans = nums[0]
        for num in nums[1:]:
            mn, mx = min(num, num * mx, num * mn), max(num, num * mx, num * mn)
            ans = max(ans, mx)  
        return ans