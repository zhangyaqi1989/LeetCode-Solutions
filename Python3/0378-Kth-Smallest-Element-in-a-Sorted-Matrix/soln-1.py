class Solution:
    def kthSmallest(self, matrix: List[List[int]], k: int) -> int:
        lo, hi = matrix[0][0], matrix[-1][-1]
        k -= 1
        while lo < hi:
            mid = hi - (hi - lo) // 2
            cnt = sum(bisect.bisect_left(row, mid) for row in matrix)
            if cnt > k:
                hi = mid - 1
            else:
                lo = mid
        return lo
