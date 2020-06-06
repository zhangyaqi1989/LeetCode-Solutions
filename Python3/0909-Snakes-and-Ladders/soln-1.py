class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        # this is a bfs
        def num_to_rc(num):
            N = len(board)
            num -= 1
            r, c = divmod(num, N)
            if r % 2:
                c = N - 1 - c
            r = N - 1 - r
            return r, c
        frontier = collections.deque([1])
        seen = {1}
        target = len(board) * len(board)
        step = 0
        while frontier:
            sz = len(frontier)
            for _ in range(sz):
                x = frontier.popleft()
                if x == target:
                    return step
                for dx in range(1, 7):
                    nx = x + dx
                    if nx <= target:
                        r, c = num_to_rc(nx)
                        if board[r][c] != -1:
                            nx = board[r][c]
                        if nx not in seen:
                            seen.add(nx)
                            frontier.append(nx)
            step += 1
        return -1
