class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        a, b, c = sorted([a, b, c])
        mx = c - b - 1 + (b - a - 1)
        if a + 1 == b and c == b + 1:
            mn = 0
        elif (a + 2 == b or b + 2 == c) or (a + 1 == b or b + 1 == c):
            mn = 1
        else:
            mn = 2
        return [mn, mx]
