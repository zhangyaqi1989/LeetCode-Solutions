class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        lo = 0
        ones = 0
        mx = 0
        for i, num in enumerate(A):
            ones += num == 1
            while i - lo + 1 - ones > K:
                ones -= A[lo] == 1
                lo += 1
            mx = max(mx, i - lo + 1)
        return mx
