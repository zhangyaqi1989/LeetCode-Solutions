class Solution:
    def frogPosition(self, n: int, edges: List[List[int]], t: int, target: int) -> float:
        # tree = collections.defaultdict(list)
        tree = [[] for _ in range(n + 1)]
        for u, v in edges:
            tree[u].append(v)
            tree[v].append(u)
        self.prob = 0.0
        visited = set()
        def dfs(node, t, prob, visited):
            if t < 0:
                return
            if t == 0 and node == target:
                self.prob += prob
            visited.add(node)
            cands = [nei for nei in tree[node] if nei not in visited]
            if cands:
                new_prob = prob / len(cands)
                for cand in cands:
                    dfs(cand, t - 1, new_prob, visited)
            else:
                if node == target and t != 0:
                    self.prob += prob
            visited.remove(node)
        dfs(1, t, 1.0, visited)
        return self.prob
