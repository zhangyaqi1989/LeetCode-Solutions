class Solution:
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        tree = [[] for _ in range(n)]
        # a --> b
        for a, b in connections:
            tree[a].append((b, 1))
            tree[b].append((a, 0))
        self.ans = 0
        def dfs(u, parent):
            for v, d in tree[u]:
                if v != parent:
                    if d == 1:
                        self.ans += 1
                    dfs(v, u)
        dfs(0, -1)
        return self.ans
