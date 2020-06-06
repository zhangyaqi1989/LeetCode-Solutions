class Solution:
    def minSwapsCouples(self, row):
        """
        :type row: List[int]
        :rtype: int
        """
        cnt, n = 0, len(row)
        for i in range(0, n, 2):
            # check i and i + 1
            if abs(row[i] - row[i + 1]) != 1 or min(row[i], row[i + 1]) & 1 != 0:
                for j in range(i + 2, n):
                    if abs(row[i] - row[j]) == 1 and min(row[i], row[j]) & 1 == 0:
                        row[i + 1], row[j] = row[j], row[i + 1]
                cnt += 1
        return cnt