class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        for key, group in itertools.groupby(nums):
            cnt = min(2, len(list(group)))
            for _ in range(cnt):
                nums[i] = key
                i += 1
        return i