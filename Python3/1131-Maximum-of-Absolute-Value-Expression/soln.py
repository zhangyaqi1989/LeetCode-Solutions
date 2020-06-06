class Solution:
    def maxAbsValExpr(self, arr1: List[int], arr2: List[int]) -> int:
        ans = 0
        n = len(arr1)
        for a, b in (1, 1), (1, -1), (-1, -1), (-1, 1):
            mn = a * arr1[0] + b * arr2[0] + 0
            for i in range(n):
                cur = a * arr1[i] + b * arr2[i] + i
                ans = max(ans, cur - mn)
                mn = min(mn, cur)
        return ans
