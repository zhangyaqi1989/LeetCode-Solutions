class Solution:
    def getSkyline(self, buildings: List[List[int]]) -> List[List[int]]:
        events = []
        for L, R, H in buildings:
            events.append((L, -H, R))
            events.append((R, 0, 0))
        ans = [(0, 0)]
        live = [(0, math.inf)]
        for L, H, R in sorted(events):
            while live[0][1] <= L:
                heapq.heappop(live)
            if H != 0:
                heapq.heappush(live, (H, R))
            if ans[-1][-1] != -live[0][0]:
                ans.append((L, -live[0][0]))
        return ans[1:]
