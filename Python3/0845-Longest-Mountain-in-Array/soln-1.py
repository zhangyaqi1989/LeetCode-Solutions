class Solution:
    def longestMountain(self, A: List[int]) -> int:
        n = len(A)
        up = down = ans = 0
        for i in range(1, n):
            if (down and A[i] >= A[i - 1]) or (A[i] == A[i - 1]):
                up = down = 0
            down += A[i] < A[i - 1]
            up += A[i] > A[i - 1]
            if up and down:
                ans = max(ans, up + down + 1)
        return ans
