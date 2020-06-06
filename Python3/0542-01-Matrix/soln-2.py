class Solution:
    def updateMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        queue = collections.deque()
        for i, row in enumerate(matrix):
            for j, val in enumerate(row):
                if val == 0:
                    queue.append((i, j))
                else:
                    matrix[i][j] = float('inf')
        m, n = len(matrix), len(matrix[0])
        step = 0
        while queue:
            step += 1
            size = len(queue)
            for _ in range(size):
                i, j = queue.popleft()
                for di, dj in ((-1, 0), (1, 0), (0, 1), (0, -1)):
                    newi, newj = i + di, j + dj
                    if 0 <= newi < m and 0 <= newj < n and matrix[newi][newj] == float('inf'):
                        matrix[newi][newj] = step
                        queue.append((newi, newj))
        return matrix