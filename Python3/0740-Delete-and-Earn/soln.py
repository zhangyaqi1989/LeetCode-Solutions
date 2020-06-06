class Solution:
    def deleteAndEarn(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        counts = collections.Counter(nums)
        mn = min(counts)
        mx = max(counts)
        pre, cur = 0, 0
        for num in range(mn, mx + 1):
            pre, cur = cur, max(cur, pre + counts[num] * num)
        return cur
