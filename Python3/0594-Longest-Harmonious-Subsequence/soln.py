class Solution:
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        counter = {}
        for num in nums:
            counter[num] = counter.get(num, 0) + 1
        # counter = collections.Counter(nums)
        res = 0
        for key, cnt in counter.items():
            if key + 1 in counter and cnt + counter[key + 1] > res:
                res = cnt + counter[key + 1]
        return res