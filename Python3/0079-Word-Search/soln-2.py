class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        if not any(board):
            return False
        def dfs(i, j, idx):
            if idx == len(word):
                return True
            if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or seen[i][j] or board[i][j] != word[idx]:
                return False
            seen[i][j] = True
            for ni, nj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                if dfs(ni, nj, idx + 1):
                    return True
            seen[i][j] = False
            return False
            
        m, n = len(board), len(board[0])
        seen = [[False] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if dfs(i, j, 0):
                    return True
        return False
        
