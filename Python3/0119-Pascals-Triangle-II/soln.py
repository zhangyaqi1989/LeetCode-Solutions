class Solution:
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        def pascal(row):
            return [1] + [row[i] + row[i + 1] for i in range(len(row) - 1)] + [1]
        row = [1]
        for _ in range(rowIndex):
            row = pascal(row)
        return row