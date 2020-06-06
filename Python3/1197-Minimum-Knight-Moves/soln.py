class Solution:
    def minKnightMoves(self, x: int, y: int) -> int:
        def neighbor(i, j):
            for di in (1, -1, 2, -2):
                dj = 3 - abs(di)
                yield i + di, j + dj
                yield i + di, j - dj
        def hfunc(i, j):
            return (max(abs(i - x), abs(j - y)) + 1) // 2
        costs = {(0, 0) : 0}
        frontier = [(hfunc(0, 0), 0, 0)]
        while frontier:
            _, i, j = heapq.heappop(frontier)
            c = costs[i, j]
            if hfunc(i, j) == 0:
                return c
            for ni, nj in neighbor(i, j):
                if (ni, nj) not in costs or c + 1 < costs[ni, nj]:
                    costs[ni, nj] = c + 1
                    heapq.heappush(frontier, (c + 1 + hfunc(ni, nj), ni, nj))
