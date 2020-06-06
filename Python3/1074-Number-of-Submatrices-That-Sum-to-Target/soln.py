class Solution:
    def numSubmatrixSumTarget(self, A: List[List[int]], target: int) -> int:
        m, n = len(A), len(A[0])
        for row in A:
            for i in range(1, n):
                row[i] += row[i - 1]
        cnt = 0
        for left in range(n):
            for right in range(left, n):
                memo = collections.Counter()
                memo[0] = 1
                cur = 0
                for i in range(m):
                    cur += A[i][right]
                    cur -= A[i][left - 1] if left >= 1 else 0
                    cnt += memo[cur - target]
                    memo[cur] += 1
        return cnt
