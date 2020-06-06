class Solution:
    def findRedundantConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        tree = ''.join(map(chr, range(1001)))
        for u, v in edges:
            if tree[u] == tree[v]:
                return [u, v]
            tree = tree.replace(tree[u], tree[v])