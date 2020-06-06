class Solution:
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # subarray == K
        # first compute the accumulated array
        acc = [0]
        for num in nums:
            acc.append(acc[-1] + num)
        d = collections.defaultdict(list)
        for i, num in enumerate(acc):
            d[num].append(i)
        res = 0
        for i in range(1, len(nums) + 1):
            need = acc[i] - k
            if need in d:
                idx = bisect.bisect_left(d[need], i)
                res += idx
        return res