class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        parents = {}
        self.count = 0
        for i, j in stones:
            parents[(i, j)] = (i, j)
            self.count += 1
        def find(x):
            if parents[x] != x:
                parents[x] = find(parents[x])
            return parents[x]
        def unite(x, y):
            rx, ry = find(x), find(y)
            if rx != ry:
                self.count -= 1
                parents[rx] = ry
        n = len(stones)
        for i in range(n):
            for j in range(i + 1, n):
                if stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]:
                    unite(tuple(stones[i]), tuple(stones[j]))
        return n - self.count
