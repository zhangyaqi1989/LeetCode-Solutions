class Solution:
    def maximumMinimumPath(self, A: List[List[int]]) -> int:
        # compute the maximum value of the score
        h, w = len(A), len(A[0])
        processed = [False] * (h * w)
        frontier = [(-A[0][0], 0, 0)]
        scores = [-1] * (h * w)
        scores[0] = A[0][0]
        target = h * w - 1
        while frontier:
            score, r, c = heapq.heappop(frontier)
            score = -score
            idx = r * w + c
            if idx == target:
                return score
            if processed[idx]:
                continue
            processed[idx] = True
            for dr, dc in (0, 1), (0, -1), (1, 0), (-1, 0):
                nr, nc = r + dr, c + dc
                if 0 <= nr < h and 0 <= nc < w:
                    new_score = min(score, A[nr][nc])
                    new_idx = nr * w + nc
                    if scores[new_idx] < new_score:
                        scores[new_idx] = new_score
                        heapq.heappush(frontier, (-new_score, nr, nc))
        return -1
