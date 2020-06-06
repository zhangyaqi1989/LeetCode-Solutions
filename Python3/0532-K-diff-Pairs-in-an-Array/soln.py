class Solution:
    def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        # number of unique k-diff pair
        # edge case: k == 0 and k < 0
        if k < 0: return 0
        res = 0
        counter = collections.Counter(nums)
        for key, cnt in counter.items():
            if (key - k != key and key - k in counter) or (key - k == key and counter[key] > 1):
                res += 1
        return res
