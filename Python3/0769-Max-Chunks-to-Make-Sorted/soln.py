class Solution:
    def maxChunksToSorted(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        cnt = 0
        max_seen = float('-inf')
        for i, val in enumerate(arr):
            max_seen = max(max_seen, val)
            if max_seen <= i:
                cnt += 1
        return cnt