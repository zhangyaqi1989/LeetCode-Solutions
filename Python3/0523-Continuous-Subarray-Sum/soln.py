class Solution:
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        k = abs(k)
        seen = {0 : -1}
        acc  = 0
        for i, num in enumerate(nums):
            acc += num
            if k != 0:
                acc = acc % k
            if acc in seen:
                if i - seen[acc] > 1:
                    return True
            else:
                seen[acc] = i
        return False
