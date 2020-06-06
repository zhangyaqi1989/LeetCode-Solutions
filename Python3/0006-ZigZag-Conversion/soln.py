import functools
class Solution:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1 or len(s) <= numRows:
            return s
        rows = [[] for _ in range(numRows)]
        row, drow = 0, 1
        for ch in s:
            rows[row].append(ch)
            row += drow
            if row == 0 or row == numRows - 1:
                drow = -drow
        return ''.join(functools.reduce(operator.add, rows))