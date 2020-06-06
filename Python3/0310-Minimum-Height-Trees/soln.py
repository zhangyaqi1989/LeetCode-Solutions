class Solution:
    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        # remove edges gradually
        tree = collections.defaultdict(set)
        for a, b in edges:
            tree[a].add(b)
            tree[b].add(a)
        ans = set(range(n))
        while n > 2:
            nodes = [v for v in tree if len(tree[v]) == 1]
            for node in nodes:
                ans.remove(node)
                nei = tree.pop(node).pop()
                tree[nei].remove(node)
            n -= len(nodes)
        return list(ans)