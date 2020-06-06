class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        x, y, z = sorted((a, b, c))
        mx = z - x - 2
        if mx == 0:
            mn = 0
        # 1 2 10 or 1 3 5
        elif (x + 1 == y or y + 1 == z) or (x + 2 == y or y + 2 == z):
            mn = 1
        else:
            mn = 2
        return [mn, mx]
