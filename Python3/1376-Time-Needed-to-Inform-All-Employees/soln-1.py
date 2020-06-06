class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        children = [[] for _ in range(n)]
        for i, m in enumerate(manager):
            if m != -1:
                children[m].append(i)
        costs = [-1] * n
        costs[headID] = 0
        frontier = [headID]
        while frontier:
            next_level = []
            for u in frontier:
                for v in children[u]:
                    costs[v] = costs[u] + informTime[u]
                    next_level.append(v)
            frontier = next_level
        return max(costs)
