class Solution:
    def containsNearbyAlmostDuplicate(self, nums, k, t):
        """
        :type nums: List[int]
        :type k: int
        :type t: int
        :rtype: bool
        """
        # abs val: t
        # abs idx: k
        if t < 0: return False
        w = t + 1
        d = {}
        for i, num in enumerate(nums):
            bucket_idx = num // w
            if bucket_idx in d:
                return True
            if bucket_idx - 1 in d and abs(num - d[bucket_idx - 1]) < w:
                return True
            if bucket_idx + 1 in d and abs(num - d[bucket_idx + 1]) < w:
                return True
            d[bucket_idx] = num
            if i >= k:
                d.pop(nums[i - k] // w)
        return False
