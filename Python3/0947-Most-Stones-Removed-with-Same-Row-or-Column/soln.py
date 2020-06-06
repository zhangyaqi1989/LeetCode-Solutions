class Solution:
    def removeStones(self, stones):
        """
        :type stones: List[List[int]]
        :rtype: int
        """
        parent = {}
        def find(x):
            if x != parent[x]:
                parent[x] = find(parent[x])
            return parent[x]
        def union(x, y):
            parent.setdefault(x, x)
            parent.setdefault(y, y)
            parent[find(x)] = find(y)
        for x, y in stones:
            union(x, ~y)
        return len(stones) - len({find(x) for x in parent})