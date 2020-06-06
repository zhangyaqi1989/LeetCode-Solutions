class Solution:
    def wallsAndGates(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: void Do not return anything, modify rooms in-place instead.
        """
        if not any(rooms): return
        queue = collections.deque()
        for i, row in enumerate(rooms):
            for j, val in enumerate(row):
                if val == 0:
                    queue.append((i, j, 0))
        m, n = len(rooms), len(rooms[0])
        while queue:
            i, j, dis = queue.popleft()
            dis += 1
            for di, dj in ((-1, 0), (1, 0), (0, 1), (0, -1)):
                newi, newj = i + di, j + dj
                if 0 <= newi < m and 0 <= newj < n and rooms[newi][newj] != -1:
                    if rooms[newi][newj] > dis:
                        rooms[newi][newj] = dis
                        queue.append((newi, newj, dis))