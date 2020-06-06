class Solution:
    def totalNQueens(self, n: int) -> int:
        self.ans = 0
        def dfs(cand, n):
            if len(cand) == n:
                self.ans += 1
            r = len(cand)
            for c in range(n):
                for i, j in enumerate(cand):
                    if j == c or i + j == r + c or i - j == r - c:
                        break
                else:
                    cand.append(c)
                    dfs(cand, n)
                    cand.pop()
        dfs([], n)
        return self.ans
