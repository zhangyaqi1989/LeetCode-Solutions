from itertools import chain, cycle
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
        for ch, row_idx in zip(s, cycle(chain(range(numRows), range(numRows - 2, 0, -1)))):
            rows[row_idx].append(ch)
        return ''.join(chain(*rows))