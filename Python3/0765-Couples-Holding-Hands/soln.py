class Solution:
    def minSwapsCouples(self, row):
        """
        :type row: List[int]
        :rtype: int
        """
        cnt = 0
        for i in range(0, len(row) - 1, 2):
            if abs(row[i] - row[i + 1]) != 1 or min(row[i], row[i + 1]) & 1 != 0:
                for j in range(i + 2, len(row)):
                    if abs(row[j] - row[i]) == 1 and min(row[i], row[j]) & 1 == 0:
                        row[i + 1], row[j] = row[j], row[i + 1]
                        cnt += 1
                        break
        return cnt


# For i = 0, 2, ..., 2N - 2:
#     if row[i], row[i + 1] are not couple:
#         find j > i such that row[i] and row[j] are couple
#         swap row[i + 1] and row[j]
