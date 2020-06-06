class Solution:
    def hasPath(self, maze, start, destination):
        """
        :type maze: List[List[int]]
        :type start: List[int]
        :type destination: List[int]
        :rtype: bool
        """
        m, n = len(maze), len(maze[0])
        start, destination = tuple(start), tuple(destination)
        visited = {start}
        stack = [start]
        while stack:
            i, j = stack.pop()
            if (i, j) == destination:
                return True
            for di, dj in ((-1, 0), (1, 0), (0, 1), (0, -1)):
                newi, newj = i + di, j + dj
                while 0 <= newi < m and 0 <= newj < n and maze[newi][newj] != 1:
                    newi, newj = newi + di, newj + dj
                newi, newj = newi - di, newj - dj
                if (newi, newj) not in visited:
                    visited.add((newi, newj))
                    stack.append((newi, newj))
        return False