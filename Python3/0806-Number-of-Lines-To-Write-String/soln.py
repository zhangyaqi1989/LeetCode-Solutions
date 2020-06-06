class Solution:
    def numberOfLines(self, widths, S):
        """
        :type widths: List[int]
        :type S: str
        :rtype: List[int]
        """
        if not S: return 0, 0
        rows, col = 1, 0
        for idx in map(lambda x: ord(x) - 97, S):
            if col + widths[idx] <= 100:
                col += widths[idx]
            else:
                rows += 1
                col = widths[idx]
        return rows, col