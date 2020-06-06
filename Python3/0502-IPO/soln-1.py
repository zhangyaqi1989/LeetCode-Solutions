class Solution:
    def findMaximizedCapital(self, k: int, W: int, Profits: List[int], Capital: List[int]) -> int:
        # priority queue
        cps = sorted((c, p) for c, p in zip(Capital, Profits))
        projects = []
        i, n = 0, len(cps)
        for _ in range(k):
            while i < n and cps[i][0] <= W:
                heapq.heappush(projects, -cps[i][1])
                i += 1
            if projects: 
                W -= heapq.heappop(projects)
            else:
                break
        return W
