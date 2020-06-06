class Solution:
    def maxChunksToSorted(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        counter1, counter2 = collections.Counter(), collections.Counter()
        sorted_arr = sorted(arr)
        cnt = 0
        for val1, val2 in zip(sorted_arr, arr):
            counter1[val1] += 1
            counter2[val2] += 1
            if counter1 == counter2:
                cnt += 1
        return cnt