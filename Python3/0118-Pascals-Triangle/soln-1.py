class Solution:
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        if not numRows: return []
        def pascal(row):
            return [1] + [row[i] + row[i + 1] for i in range(len(row) - 1)] + [1]
        ans = [[1]]
        for _ in range(numRows - 1):
            ans.append(pascal(ans[-1]))
        return ans