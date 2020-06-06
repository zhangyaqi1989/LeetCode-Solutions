class Solution:
    def hasPath(self, maze, start, destination):
        """
        :type maze: List[List[int]]
        :type start: List[int]
        :type destination: List[int]
        :rtype: bool
        """
        start, target = tuple(start), tuple(destination)
        stack = [start]
        seen = {start}
        def neighbor(node):
            i, j = node
            m, n = len(maze), len(maze[0])
            for di, dj in (-1, 0), (1, 0), (0, 1), (0, -1):
                newi, newj = i + di, j + dj
                while 0 <= newi < m and 0 <= newj < n and maze[newi][newj] == 0:
                    newi, newj = newi + di, newj + dj
                yield newi - di, newj - dj
        while stack:
            node = stack.pop()
            if node == target:
                return True
            for nei in neighbor(node):
                if nei not in seen:
                    seen.add(nei)
                    stack.append(nei)
        return False
