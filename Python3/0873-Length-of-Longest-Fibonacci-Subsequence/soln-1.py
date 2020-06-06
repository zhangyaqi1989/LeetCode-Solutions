class Solution:
    def lenLongestFibSubseq(self, A: List[int]) -> int:
        s = set(A)
        mx = 0
        n = len(A)
        for i in range(n - 1):
            for j in range(i + 1, n):
                a, b = A[i], A[j]
                cur = 2
                while a + b in s:
                    a, b = b, a + b
                    cur += 1
                mx = max(mx, cur)
        return mx if mx >= 3 else 0
