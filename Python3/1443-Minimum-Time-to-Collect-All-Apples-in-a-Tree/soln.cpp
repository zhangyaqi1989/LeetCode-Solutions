class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        tree = collections.defaultdict(list)
        for u, v in edges:
            tree[u].append(v)
            tree[v].append(u)
        costs = [0] * n
        self.delete = 0
        def dfs(u, parent):
            child = 0
            for v in tree[u]:
                if v != parent:
                    child += dfs(v, u)
            ans = hasApple[u] + child
            if parent != -1 and ans == 0:
                self.delete += 1
            return ans
        dfs(0, -1)
        return 2 * (n - 1 - self.delete)
