class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        ans, zeros = 0, 0
        l = 0
        for r, ch in enumerate(A):
            if ch == 0:
                zeros += 1
            while zeros > K:
                zeros -= (A[l] == 0)
                l += 1
            ans = max(ans, r - l + 1)
        return ans
