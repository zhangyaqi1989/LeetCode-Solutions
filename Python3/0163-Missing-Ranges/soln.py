class Solution:
    def findMissingRanges(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: List[str]
        """
        # linear traverse
        def range_str(lo, hi):
            return str(lo) if lo == hi else "{}->{}".format(lo, hi)
        ans = []
        for num in nums:
            if num > lower:
                ans.append(range_str(lower, num - 1))
            lower = num + 1
        if lower <= upper:
            ans.append(range_str(lower, upper))
        return ans