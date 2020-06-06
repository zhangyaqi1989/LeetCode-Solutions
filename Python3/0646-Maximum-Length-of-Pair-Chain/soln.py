class Solution:
    def findLongestChain(self, pairs):
        """
        :type pairs: List[List[int]]
        :rtype: int
        """
        pairs = sorted(pairs, key=lambda x : (x[1], x[0]))
        low, cnt = -math.inf, 0
        for start, end in pairs:
            if start > low:
                cnt += 1
                low = end
        return cnt
