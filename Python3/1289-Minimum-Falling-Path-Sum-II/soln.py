class Solution:
    def minFallingPathSum(self, arr: List[List[int]]) -> int:
        m, n = len(arr), len(arr[0])
        for i in range(1, m):
            mn = min(arr[i - 1])
            mn_idx = arr[i - 1].index(mn)
            second_mn = min(arr[i - 1][:mn_idx] + arr[i - 1][mn_idx + 1:])
            for j in range(n):
                if j != mn_idx:
                    arr[i][j] += mn
                else:
                    arr[i][j] += second_mn
        return min(arr[-1])
