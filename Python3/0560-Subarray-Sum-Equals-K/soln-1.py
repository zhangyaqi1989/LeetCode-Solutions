class Solution:
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        acc = collections.Counter()
        acc[0] = 1
        total = 0
        res = 0
        for num in nums:
            total += num
            need = total - k
            res += acc[need]
            acc[total] += 1
        return res