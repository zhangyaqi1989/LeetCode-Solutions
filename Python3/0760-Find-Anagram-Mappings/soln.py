class Solution:
    def anagramMappings(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        m = collections.defaultdict(list)
        for idx, val in enumerate(B):
            m[val].append(idx)
        res = []
        for idx, val in enumerate(A):
            res.append(m[val].pop())
        return res