class Solution:
    def findCheapestPrice(self, n, flights, src, dst, K):
        """
        :type n: int
        :type flights: List[List[int]]
        :type src: int
        :type dst: int
        :type K: int
        :rtype: int
        """
        graph = collections.defaultdict(dict)
        for a, b, price in flights:
            graph[a][b] = price
        heap = [(0, src, K + 1)]
        while heap:
            p, node, k = heapq.heappop(heap)
            if node == dst:
                return p
            if k > 0:
                for nei in graph[node]:
                    heapq.heappush(heap, (p + graph[node][nei], nei, k - 1))
        return -1