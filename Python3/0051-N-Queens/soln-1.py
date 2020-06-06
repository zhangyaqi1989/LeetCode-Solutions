class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        ans = []
        def dfs(cand, n):
            if len(cand) == n:
                ans.append(cand[:])
            r = len(cand)
            for c in range(n):
                for i, j in enumerate(cand):
                    if j == c or r + c == i + j or r - c == i - j:
                        break
                else:
                    cand.append(c)
                    dfs(cand, n)
                    cand.pop()
        dfs([], n)
        def convert(cand):
            ans = []
            row = ['.'] * len(cand)
            for j in cand:
                row[j] = 'Q'
                ans.append(''.join(row))
                row[j] = '.'
            return ans
        return [convert(cand) for cand in ans]
