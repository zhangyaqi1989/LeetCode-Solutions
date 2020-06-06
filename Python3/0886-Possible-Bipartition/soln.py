class Solution:
    def possibleBipartition(self, N, dislikes):
        """
        :type N: int
        :type dislikes: List[List[int]]
        :rtype: bool
        """
        B, W = 0, 1
        colors = [None] * (N + 1)
        graph = collections.defaultdict(list)
        for a, b in dislikes:
            graph[a].append(b)
            graph[b].append(a)
        def dfs(i):
            stack = [i]
            colors[i] = B
            while stack:
                node = stack.pop()
                for nei in graph[node]:
                    if colors[nei] is None:
                        colors[nei] = 1 - colors[node]
                        stack.append(nei)
                    else:
                        if colors[nei] == colors[node]:
                            return False
            return True
        for i in range(1, N + 1):
            if colors[i] is None:
                if not dfs(i):
                    return False
        return True
