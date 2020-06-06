class Solution:
    def totalHammingDistance(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 0
        for i in range(32):
            cnt = 0
            for num in nums:
                if (num >> i) & 1:
                    cnt += 1
            ans += cnt * (len(nums) - cnt)
        return ans