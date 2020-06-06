class Solution:
    def getFactors(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        ans = []
        self.helper(n, [], n, ans)
        return ans
    
    def helper(self, n, factors, left, ans):
        if left == 1:
            if factors:
                ans.append(factors)
        else:
            lo = 2 if not factors else factors[-1]
            for i in range(lo, min(n, left + 1)):
                if left % i == 0:
                    self.helper(n, factors + [i], left // i, ans)
