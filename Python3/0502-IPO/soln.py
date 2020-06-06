class Solution:
    def findMaximizedCapital(self, k, W, Profits, Capital):
        """
        :type k: int
        :type W: int
        :type Profits: List[int]
        :type Capital: List[int]
        :rtype: int
        """
        heap = []
        i = 0
        projects = sorted(zip(Profits, Capital), key=lambda x : x[1])
        for _ in range(k):
            while i < len(projects) and projects[i][1] <= W:
                heapq.heappush(heap, -projects[i][0])
                i += 1
            if heap: W -= heapq.heappop(heap)
        return W