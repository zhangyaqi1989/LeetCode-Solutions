class Solution:
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        # linear traverse
        if not nums: return []
        def range_str(lo, hi):
            return str(lo) if hi == lo else "{}->{}".format(lo, hi)
        low, cur, ans = nums[0], nums[0], []
        for num in nums[1:] + [float('inf')]:
            if num - cur > 1:
                ans.append(range_str(low, cur))
                low = num
            cur = num
        return ans