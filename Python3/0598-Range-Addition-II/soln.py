class Solution:
    def maxCount(self, m, n, ops):
        """
        :type m: int
        :type n: int
        :type ops: List[List[int]]
        :rtype: int
        """
        if not ops: return m * n
        return min(a for a, _ in ops) * min(b for _, b in ops)