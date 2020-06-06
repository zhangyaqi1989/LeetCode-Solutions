class Solution:
    def minTotalDistance(self, grid: List[List[int]]) -> int:
        # [2,0,1]
        def helper(arr):
            l = -1
            r = len(arr)
            left = right = 0
            lcnt = rcnt = 0
            while l < r:
                if lcnt < rcnt:
                    l += 1
                    left += lcnt
                    lcnt += arr[l]
                else:
                    r -= 1
                    right += rcnt
                    rcnt += arr[r]
            return left + right
        rows = [sum(row) for row in grid]
        cols = [sum(col) for col in zip(*grid)]
        return helper(rows) + helper(cols)
