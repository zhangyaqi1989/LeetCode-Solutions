class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        counter = {0 : 1}
        acc, cnt = 0, 0
        for num in nums:
            acc += num
            cnt += counter.get(acc - k, 0)
            counter[acc] = counter.get(acc, 0) + 1
        return cnt