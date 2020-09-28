class Solution:
    def maximumRequests(self, n: int, requests: List[List[int]]) -> int:
        self.best = 0
        def dfs(idx, cnt, changes):
            if all(c == 0 for c in changes):
                self.best = max(self.best, cnt)
            if idx == len(requests):
                return
            dfs(idx + 1, cnt, changes)
            f, t = requests[idx]
            changes[f] -= 1
            changes[t] += 1
            dfs(idx + 1, cnt + 1, changes)
            changes[f] += 1
            changes[t] -= 1
        dfs(0, 0, [0] * n)
        return self.best
