class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        ones = [sum(row) for row in mat]
        return heapq.nsmallest(k, range(len(mat)), key=lambda x : (ones[x], x))
