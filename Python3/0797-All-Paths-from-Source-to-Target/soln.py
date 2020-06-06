class Solution:
    def allPathsSourceTarget(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: List[List[int]]
        """
        # all paths
        def dfs(node, path):
            if node == len(graph) - 1:
                ans.append(path)
            for nei in graph[node]:
                dfs(nei, path + [nei])
        ans = []
        dfs(0, [0])
        return ans