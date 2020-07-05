class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        h, w = len(mat), len(mat[0])
        ones = [[0] * w for _ in range(h)]
        for i, row in enumerate(mat):
            for j, val in enumerate(row):
                if val == 1:
                    ones[i][j] = 1 if j == 0 else ones[i][j - 1] + 1
        ans = 0
        for i, row in enumerate(mat):
            for j, val in enumerate(row):
                if val == 1:
                    left = ones[i][j]
                    r = i
                    while r >= 0 and mat[r][j] == 1:
                        left = min(left, ones[r][j])
                        ans += left
                        r -= 1
        return ans
