class Solution:
    def kthSmallest(self, mat: List[List[int]], k: int) -> int:
        h, w = len(mat), len(mat[0])
        lo = sum(row[0] for row in mat)
        cur = [0] * h
        pq = [(lo, cur)]
        visited = {tuple(cur)}
        while pq:
            lo, cur = heapq.heappop(pq)
            k -= 1
            if k == 0:
                return lo
            for r in range(h):
                if cur[r] + 1 < w:
                    cur[r] += 1
                    nxt = tuple(cur)
                    if nxt not in visited:
                        visited.add(nxt)
                        heapq.heappush(pq, (lo - mat[r][cur[r] - 1] + mat[r][cur[r]], cur[:]))
                    cur[r] -= 1
        return -1
