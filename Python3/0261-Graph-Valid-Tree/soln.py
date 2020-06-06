class Solution:
    def validTree(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: bool
        """
        # for n nodes, there are only n - 1 edges
        # and they are connected
        if len(edges) != n - 1:
            return False
        graph = collections.defaultdict(list)
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)
        stack = [0]
        visited = {0}
        while stack:
            node = stack.pop()
            for nei in graph[node]:
                if nei not in visited:
                    visited.add(nei)
                    stack.append(nei)
        return len(visited) == n