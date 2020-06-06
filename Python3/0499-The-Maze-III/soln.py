class Solution:
    def findShortestWay(self, maze, ball, hole):
        """
        :type maze: List[List[int]]
        :type ball: List[int]
        :type hole: List[int]
        :rtype: str
        """
        ball = tuple(ball)
        hole = tuple(hole)
        # previous = {ball : None}
        previous = collections.defaultdict(list)
        pq = [(0, ball)]
        m, n = len(maze), len(maze[0])
        costs = {ball : 0}
        ans = collections.defaultdict(list)
        def compute_ops(path):
            ans = []
            for (r1, c1), (r2, c2) in zip(path, path[1:]):
                if r2 < r1:
                    ans.append('u')
                elif r2 > r1:
                    ans.append('d')
                elif c2 > c1:
                    ans.append('r')
                elif c2 < c1:
                    ans.append('l')
            return ''.join(ans)
        
        def compute_path_cost(path):
            return sum(abs(r1 - r2) + abs(c1 - c2) for (r1, c1), (r2, c2) in zip(path, path[1:]))
        
        def compute_paths(a):
            return [[a]] if not previous[a] else ([sub + [a] for pre in previous[a] for sub in compute_paths(pre)])
        min_cost = math.inf
        ans = ''
        while pq:
            cost, (i, j) = heapq.heappop(pq)
            for di, dj in (-1, 0), (1, 0), (0, -1), (0, 1):
                newi, newj = i + di, j + dj
                while 0 <= newi < m and 0 <= newj < n and maze[newi][newj] == 0:
                    if (newi, newj) == hole:
                        paths = [path + [hole] for path in compute_paths((i, j))]
                        for path in paths:
                            path_cost = compute_path_cost(path)
                            if path_cost < min_cost:
                                min_cost = path_cost
                                ans = compute_ops(path)
                            elif path_cost == min_cost:
                                ops = compute_ops(path)
                                if ops < ans:
                                    ans = ops
                        break
                    newi, newj = newi + di, newj + dj
                else:
                    newi, newj = newi - di, newj - dj
                    new_cost = cost + ( (newi - i) // di if di != 0 else (newj - j) // dj)
                    if (newi, newj) in costs and costs[(newi, newj)] == new_cost:
                        if (newi, newj) != (i, j):
                            previous[(newi, newj)].append((i, j))
                    if (newi, newj) not in costs or costs[(newi, newj)] > new_cost:
                        costs[(newi, newj)] = new_cost
                        previous[(newi, newj)] = [(i, j)]
                        heapq.heappush(pq, (new_cost, (newi, newj)))
        if not ans:
            return 'impossible'
        return ans
