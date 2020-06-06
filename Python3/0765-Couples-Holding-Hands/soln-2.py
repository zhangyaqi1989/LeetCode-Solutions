class Solution:
    def minSwapsCouples(self, row: List[int]) -> int:
        n = len(row)
        cnt = 0
        for i in range(0, n, 2):
            if abs(row[i] - row[i + 1]) != 1 or min(row[i], row[i + 1]) & 1 == 1:
                cnt += 1
                for j in range(i + 2, n):
                    if abs(row[j] - row[i]) == 1 and min(row[i], row[j]) & 1 == 0:
                        row[j], row[i + 1] = row[i + 1], row[j]
                        break
        return cnt
