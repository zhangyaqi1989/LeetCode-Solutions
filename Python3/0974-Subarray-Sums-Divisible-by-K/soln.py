class Solution:
    def subarraysDivByK(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        accs = [0] + list(itertools.accumulate(A))
        counter = collections.Counter()
        ans = 0
        for acc in accs:
            r = acc % K
            ans += counter[r]
            counter[r] += 1
        return ans
