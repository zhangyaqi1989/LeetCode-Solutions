class Solution:
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        d = {}
        max_cnt = 1
        for i, num in enumerate(nums):
            if num not in d:
                d[num] = [1, i, i]
            else:
                d[num][0] += 1
                if d[num][0] > max_cnt:
                    max_cnt = d[num][0]
                d[num][-1] = i
        return min(last - first for cnt, first, last in d.values() if cnt == max_cnt) + 1