class Solution:
    def snakesAndLadders(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        # this is a BFS
        N = len(board)
        queue = collections.deque([1])
        visited = {1}
        step = 0
        while queue:
            step += 1
            size = len(queue)
            for _ in range(size):
                x = queue.popleft()
                for i in range(x + 1, x + 7):
                    r, c = (i - 1) // N, (i - 1) % N
                    val = board[~r][~c if r % 2 else c]
                    if val > 0:
                        i = val
                    if i == N * N: return step
                    if i not in visited:
                        visited.add(i)
                        queue.append(i)
        return -1