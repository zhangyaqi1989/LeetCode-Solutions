class Solution:
    def numFactoredBinaryTrees(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        tree = {}
        for a in sorted(A):
            tree[a] = 1 + sum(tree[b] * tree.get(a // b, 0) for b in tree if a % b == 0)
        return sum(tree.values()) % (1_000_000_000 + 7)
