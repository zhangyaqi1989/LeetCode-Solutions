class Solution:
    def treeDiameter(self, edges: List[List[int]]) -> int:
        def dfs(node, parent, distance):
            if distance > self.max_distance:
                self.max_distance = distance
                self.furthest_node = node
            for nei in tree[node]:
                if nei != parent:
                    dfs(nei, node, distance + 1)
        n = len(edges) + 1
        tree = [[] for _ in range(n)]
        for u, v in edges:
            tree[u].append(v)
            tree[v].append(u)
        self.furthest_node = -1
        self.max_distance = 0
        dfs(0, -1, 0)
        self.max_distance = 0
        dfs(self.furthest_node, -1, 0)
        return self.max_distance
