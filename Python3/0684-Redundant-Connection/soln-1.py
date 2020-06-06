class Solution:
    def findRedundantConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        def find(union, x):
            if union[x] == -1:
                return x
            return find(union, union[x])
        union = [-1] * 1001
        for u, v in edges:
            a = find(union, u)
            b = find(union, v)
            if a == b:
                return [u, v]
            union[a] = b