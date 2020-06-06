class Solution:
    def shortestBridge(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        # BFS
        m, n = len(A), len(A[0])
        for i, row in enumerate(A):
            for j, val in enumerate(row):
                if val == 1:
                    stack = [(i, j)]
                    queue = collections.deque()
                    visited = set()
                    A[i][j] = 0
                    while stack:
                        i, j = stack.pop()
                        queue.append((i, j))
                        visited.add((i, j))
                        for di, dj in ((-1, 0), (1, 0), (0, 1), (0, -1)):
                            newi, newj = i + di, j + dj
                            if 0 <= newi < m and 0 <= newj < n and A[newi][newj] == 1:
                                A[newi][newj] = 0
                                stack.append((newi, newj))
                    step = 0
                    while queue:
                        size = len(queue)
                        step += 1
                        for _ in range(size):
                            i, j = queue.popleft()
                            for di, dj in ((-1, 0), (1, 0), (0, 1), (0, -1)):
                                newi, newj = i + di, j + dj
                                if 0 <= newi < m and 0 <= newj < n and (newi, newj) not in visited:
                                    if A[newi][newj] == 1:
                                        return step - 1
                                    queue.append((newi, newj))
                                    visited.add((newi, newj))
                    return step