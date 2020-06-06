class Solution:
    def cutOffTree(self, forest: List[List[int]]) -> int:
        def bfs(start, end):
            dq = collections.deque([start])
            steps = 0
            visited = {start}
            m, n = len(forest), len(forest[0])
            while dq:
                sz = len(dq)
                for _ in range(sz):
                    node = dq.popleft()
                    if node == end:
                        return steps
                    i, j = node
                    for ni, nj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                        if 0 <= ni < m and 0 <= nj < n and forest[ni][nj] != 0 and (ni, nj) not in visited:
                            visited.add((ni, nj))
                            dq.append((ni, nj))
                steps += 1
            return -1
        
        def astar(start, end):
            def h_func(node):
                return abs(node[0] - end[0]) + abs(node[1] - end[1])
            m, n = len(forest), len(forest[0])
            frontier = [(h_func(start), start)]
            path_cost = {start : 0}
            while frontier:
                f, (i, j) = heapq.heappop(frontier)
                if h_func((i, j)) == 0:
                    return path_cost[(i, j)]
                for ni, nj in (i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1):
                    if 0 <= ni < m and 0 <= nj < n and forest[ni][nj] != 0:
                        new_cost = path_cost[(i, j)] + 1
                        if (ni, nj) not in path_cost or new_cost < path_cost[ni, nj]:
                            path_cost[ni, nj] = new_cost
                            heapq.heappush(frontier, (new_cost + h_func((ni, nj)), (ni, nj)))
            return -1
                
        trees = []
        for i, row in enumerate(forest):
            for j, val in enumerate(row):
                if val > 1:
                    trees.append((val, i, j))
                    
        r, c = 0, 0
        ans = 0
        for _, i, j in sorted(trees):
            d = astar((r, c), (i, j))
            if d == -1:
                return -1
            else:
                ans += d
            r, c = i, j
        return ans
        
        
