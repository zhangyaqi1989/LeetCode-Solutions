class Solution:
    def minTotalDistance(self, grid: List[List[int]]) -> int:
        def helper(arr):
            l = -1
            r = len(arr)
            ans = 0
            lcnt = rcnt = 0
            while l < r:
                if lcnt < rcnt:
                    ans += lcnt
                    l += 1
                    lcnt += arr[l]
                else:
                    ans += rcnt
                    r -= 1
                    rcnt += arr[r]
            return ans
        return helper([sum(row) for row in grid]) + helper([sum(col) for col in zip(*grid)])
