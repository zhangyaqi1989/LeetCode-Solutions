class Solution:
    def numOfBurgers(self, tomatoSlices: int, cheeseSlices: int) -> List[int]:
        # 4 * x + 2 * y = t
        # x + y = c
        x = (tomatoSlices - 2 * cheeseSlices) // 2
        y = cheeseSlices - x
        return [x, y] if (x >= 0 and y >= 0 and 4 * x + 2 * y == tomatoSlices and x + y == cheeseSlices) else []
