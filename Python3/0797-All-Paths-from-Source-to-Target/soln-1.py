class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        self.ans = []
        def dfs(path):
            if path[-1] == len(graph) - 1:
                self.ans.append(path[:])
            for nei in graph[path[-1]]:
                path.append(nei)
                dfs(path)
                path.pop()
        dfs([0])
        return self.ans
