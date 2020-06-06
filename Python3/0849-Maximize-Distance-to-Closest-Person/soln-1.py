class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        lo = -1
        ans = 1
        for i, seat in enumerate(seats):
            if seat == 1:
                if lo == -1:
                    ans = max(ans, i)
                else:
                    ans = max(ans, (i - lo) // 2)
                lo = i
        return max(ans, len(seats) - 1 - lo)
