class Solution:
    def fourSumCount(self, A, B, C, D):
        """
        :type A: List[int]
        :type B: List[int]
        :type C: List[int]
        :type D: List[int]
        :rtype: int
        """
        two_sum = collections.Counter(a + b for a in A for b in B)
        return sum(two_sum[-c - d] for c in C for d in D)
