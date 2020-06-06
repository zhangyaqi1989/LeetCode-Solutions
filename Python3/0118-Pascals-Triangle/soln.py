class Solution:
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        def generate_next_row(row):
            ans = [1]
            for i in range(len(row) - 1):
                ans.append(row[i] + row[i + 1])
            return ans + [1]
        row = [1]
        res = []
        for i in range(numRows):
            res.append(row)
            row = generate_next_row(row)
        return res