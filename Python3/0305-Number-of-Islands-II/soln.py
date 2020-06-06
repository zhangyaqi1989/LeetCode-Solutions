class Solution:
    def numIslands2(self, m, n, positions):
        """
        :type m: int
        :type n: int
        :type positions: List[List[int]]
        :rtype: List[int]
        """
        parent = {}
        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]
        def union(x, y):
            x, y = find(x), find(y)
            if x == y:
                return 0
            else:
                parent[y] = x
                return 1
        counts = []
        count = 0
        for i, j in positions:
            x = parent[x] = i, j
            count += 1
            for y in (i - 1, j), (i + 1, j), (i, j + 1), (i, j - 1):
                if y in parent:
                    count -= union(x, y)
            counts.append(count)
        return counts