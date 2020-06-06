class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def dfs(r, c, idx):
            if idx == len(word):
                return True
            if 0 <= r < len(board) and 0 <= c < len(board[0]) and word[idx] == board[r][c]:
                board[r][c] = '#'
                if dfs(r - 1, c, idx + 1) or dfs(r + 1, c, idx + 1) or dfs(r, c - 1, idx + 1) or dfs(r, c + 1, idx + 1):
                    return True
                board[r][c] = word[idx]
            else:
                return False
        for i in range(len(board)):
            for j in range(len(board[0])):
                if dfs(i, j, 0):
                    return True
        return False
