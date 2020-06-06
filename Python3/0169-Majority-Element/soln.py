class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cnt, ans = 0, -1
        for num in nums:
            if cnt == 0:
                ans = num
                cnt = 1
            else:
                if ans == num:
                    cnt += 1
                else:
                    cnt -= 1
        return ans