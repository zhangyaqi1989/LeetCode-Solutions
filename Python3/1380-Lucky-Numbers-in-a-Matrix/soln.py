class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        row_mins = [min(row) for row in matrix]
        col_maxs = [max(col) for col in zip(*matrix)]
        return [val for i, row in enumerate(matrix)
                    for j, val in enumerate(row)
                    if row_mins[i] == val == col_maxs[j]]
