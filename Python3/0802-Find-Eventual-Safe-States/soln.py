class Solution:
    def eventualSafeNodes(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[int]
        """
        # no circle
        def dfs(i):
            visited[i] = 0
            for nei in graph[i]:
                if visited[nei] == 0 or (visited[nei] == -1 and dfs(nei)):
                    return True
            visited[i] = 1
            safes.append(i)
            return False
        visited = [-1] * len(graph)
        safes = []
        for i in range(len(graph)):
            if visited[i] == -1:
                dfs(i)
        return sorted(safes)
