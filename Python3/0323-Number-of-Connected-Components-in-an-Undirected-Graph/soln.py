class Solution:
    def countComponents(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        graph = collections.defaultdict(list)
        for a, b in edges:
            graph[a].append(b)
            graph[b].append(a)
        visited = [False] * n
        def dfs(start):
            stack = [start]
            visited[start] = True
            while stack:
                node = stack.pop()
                for nei in graph[node]:
                    if not visited[nei]:
                        visited[nei] = True
                        stack.append(nei)
        cnt = 0
        for i in range(n):
            if not visited[i]:
                dfs(i)
                cnt += 1
        return cnt
