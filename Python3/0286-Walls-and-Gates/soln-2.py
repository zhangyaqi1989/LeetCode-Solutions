class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        INF = 2147483647
        queue = [(i, j) for i, row in enumerate(rooms) for j, val in enumerate(row)  if not val]
        for i, j in queue:
            for newi, newj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                if 0 <= newi < len(rooms) and 0 <= newj < len(rooms[0]) and rooms[newi][newj] == INF:
                    rooms[newi][newj] = rooms[i][j] + 1
                    queue.append((newi, newj))
