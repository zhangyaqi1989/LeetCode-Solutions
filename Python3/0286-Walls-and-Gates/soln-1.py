class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        if not any(rooms):
            return
        stack = []
        for i, row in enumerate(rooms):
            for j, val in enumerate(row):
                if val == 0:
                    stack.append((i, j))
        m, n = len(rooms), len(rooms[0])
        while stack:
            i, j = stack.pop()
            for newi, newj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                if 0 <= newi < m and 0 <= newj < n and rooms[newi][newj] != -1:
                    if rooms[newi][newj] > rooms[i][j] + 1:
                        rooms[newi][newj] = rooms[i][j] + 1
                        stack.append((newi, newj))
