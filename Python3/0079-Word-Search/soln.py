class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        def dfs(word, idx, r, c):
            m, n = len(board), len(board[0])
            if idx == len(word):
                return True
            if (not (0 <= r < m and 0 <= c < n)) or word[idx] != board[r][c]:
                return False
            for i, j in ((r - 1, c), (r + 1, c), (r, c - 1), (r, c + 1)):
                if (i, j) not in visited:
                    visited.add((i, j))
                    if dfs(word, idx + 1, i, j):
                        return True
                    visited.remove((i, j))
            return False
        visited = set()
        for i, row in enumerate(board):
            for j, val in enumerate(row):
                visited.add((i, j))
                if dfs(word, 0, i, j):
                    return True
                visited.clear()
        return False