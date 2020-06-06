class Solution(object):
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        counter = collections.Counter()
        d = {}
        for idx, num in enumerate(nums):
            counter[num] += 1
            if num in d:
                d[num][-1] = idx
            else:
                d[num] = [idx, idx]
        max_cnt = max(counter.values())
        return min(d[num][-1] - d[num][0] + 1 for num, cnt in counter.items() if cnt == max_c