class Solution:
    def getSkyline(self, buildings):
        """
        :type buildings: List[List[int]]
        :rtype: List[List[int]]
        """
        res = [[0, 0]]
        live = [(0, float('inf'))]
        events = [(L, -H, R) for L, R, H in buildings] + list({(R, 0, 0) for _, R, _ in buildings})
        events.sort()
        for pos, neiH, R in events:
            while live[0][1] <= pos:
                heapq.heappop(live)
            if neiH:
                heapq.heappush(live, (neiH, R))
            if res[-1][1] != -live[0][0]:
                res += [[pos, -live[0][0]]]
        return res[1:]