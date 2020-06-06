class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        glasses = [0] * 101
        glasses[0] = poured
        for row in range(1, query_row + 1):
            for col in range(row, -1, -1):
                glasses[col] = (max(0, glasses[col] - 1) + max(0, glasses[col - 1] - 1)) / 2
        return min(1, glasses[query_glass])
        
