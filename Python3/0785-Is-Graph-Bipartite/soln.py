class Solution:
    def isBipartite(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: bool
        """
        colors = {}
        for node in range(len(graph)):
            if node not in colors:
                colors[node] = 0
                stack = [node]
                while stack:
                    v = stack.pop()
                    for nei in graph[v]:
                        if nei not in colors:
                            colors[nei] = colors[v] ^ 1
                            stack.append(nei)
                        else:
                            if colors[nei] == colors[v]:
                                return False
        return True