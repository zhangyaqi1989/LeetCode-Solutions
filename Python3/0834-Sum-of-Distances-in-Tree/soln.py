class Solution:  
    def sumOfDistancesInTree(self, N, edges):
        tree = collections.defaultdict(list)
        for a, b in edges:
            tree[a].append(b)
            tree[b].append(a)
        count = [1] * N
        dists = [0] * N
        def dfs1(node, parent):
            for nei in tree[node]:
                if nei != parent:
                    dfs1(nei, node)
                    count[node] += count[nei]
                    dists[node] += dists[nei] + count[nei]
        def dfs2(node, parent):
            for nei in tree[node]:
                if nei != parent:
                    dists[nei] = dists[node] + N - 2 * count[nei]
                    dfs2(nei, node)
        dfs1(0, -1)
        dfs2(0, -1)
        return dists
