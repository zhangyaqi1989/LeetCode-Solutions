class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        # traverse each row, find
        N = len(grid)
        trailing_zeros = []
        for row in grid:
            j = N - 1
            while j >= 0 and row[j] == 0:
                j -= 1
            trailing_zeros.append(N - 1 - j)
        ans = 0
        for i in range(N):
            req = N - 1 - i
            idx = i
            while idx < N and trailing_zeros[idx] < req:
                idx += 1
            if idx == N:
                return -1
            ans += idx - i
            while idx > i:
                trailing_zeros[idx] = trailing_zeros[idx - 1]
                idx -= 1
        return ans
