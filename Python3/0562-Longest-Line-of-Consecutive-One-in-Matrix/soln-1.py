class Solution(object):
    def longestLine(self, M):
        """
        :type M: List[List[int]]
        :rtype: int
        """
        counter = collections.Counter()
        max_len = 0
        for i, row in enumerate(M):
            for j, val in enumerate(row):
                for key in ((1, i), (2, j), (3, i + j), (4, i - j)):
                    counter[key] = (counter[key] + 1) * val
                    max_len = max(max_len, counter[key])
        return max_len