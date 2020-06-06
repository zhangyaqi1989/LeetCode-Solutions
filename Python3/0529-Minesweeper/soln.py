class Solution:
    def updateBoard(self, board, click):
        """
        :type board: List[List[str]]
        :type click: List[int]
        :rtype: List[List[str]]
        """
        click = tuple(click)
        m, n = len(board), len(board[0])
        def neighbors(r, c):
            for dr in (-1, 0, 1):
                for dc in (-1, 0, 1):
                    if (dr or dc) and 0 <= r + dr < m and 0 <= c + dc < n:
                        yield r + dr, c + dc
        todos = [click]
        visited = {click}
        while todos:
            i, j = todos.pop()
            if board[i][j] == 'M':
                board[i][j] = 'X'
            else:
                mines = sum(board[newi][newj] in 'MX' for newi, newj in neighbors(i, j))
                if mines:
                    board[i][j] = str(mines)
                else:
                    board[i][j] = 'B'
                    for nei in neighbors(i, j):
                        if board[nei[0]][nei[1]] in 'ME' and nei not in visited:
                            visited.add(nei)
                            todos.append(nei)
        return board