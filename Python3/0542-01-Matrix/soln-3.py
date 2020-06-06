class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        m, n = len(matrix), len(matrix[0])
        queue = collections.deque()
        for i, row in enumerate(matrix):
            for j, val in enumerate(row):
                if val:
                    matrix[i][j] = math.inf
                else:
                    queue.append((i, j))
        while queue:
            i, j = queue.popleft()
            cost = matrix[i][j] + 1
            for newi, newj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                if 0 <= newi < m and 0 <= newj < n and matrix[newi][newj] > cost:
                    queue.append((newi, newj))
                    matrix[newi][newj] = cost
        return matrix
