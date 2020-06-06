class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        occupy = {}
        for row, col in reservedSeats:
            if row not in occupy:
                occupy[row] = 0
            occupy[row] |= (1 << col)
        attempts = [(2, 6), (6, 10), (4, 8)]
        ans = 0
        for row, used in occupy.items():
            n -= 1
            for lo, hi in attempts:
                if all((used & (1 << col) == 0) for col in range(lo, hi)):
                    ans += 1
                    for col in range(lo, hi):
                        used |= (1 << col)
        return ans + n * 2
        
