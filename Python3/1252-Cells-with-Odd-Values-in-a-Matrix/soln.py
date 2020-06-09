class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        rows = [0] * n
        cols = [0] * m
        for r, c in indices:
            rows[r] += 1
            cols[c] += 1
        return sum((rows[r] + cols[c]) % 2 for r in range(n) for c in range(m))
