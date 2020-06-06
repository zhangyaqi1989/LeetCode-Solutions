class Solution:
    def countArrangement(self, N):
        """
        :type N: int
        :rtype: int
        """
        # number of arrangements
        def count(i, cands):
            if i == 1:
                return 1
            return sum(count(i - 1, cands - {x}) 
                       for x in cands
                       if x % i == 0 or i % x == 0)
        return count(N, set(range(1, N + 1)))
