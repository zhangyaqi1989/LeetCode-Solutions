class Solution:
    def pacificAtlantic(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        if not any(matrix):
            return []
        m, n = len(matrix), len(matrix[0])
        def BFS(starts, m, n):
            visited = set(starts)
            queue = collections.deque(starts)
            while queue:
                i, j = queue.popleft()
                for newi, newj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                    if 0 <= newi < m and 0 <= newj < n:
                        if matrix[newi][newj] >= matrix[i][j] and (newi, newj) not in visited:
                            visited.add((newi, newj))
                            queue.append((newi, newj))
            return visited
        pacific = [(0, j) for j in range(n)] + [(i, 0) for i in range(1, m)]
        pacific_visited = BFS(pacific, m, n)
        atlantic = [(i, n - 1) for i in range(m)] + [(m - 1, j) for j in range(n - 1)]
        atlantic_visited = BFS(atlantic, m, n)
        # print(pacific_visited)
        # print(len(pacific_visited))
        return list(pacific_visited & atlantic_visited)
