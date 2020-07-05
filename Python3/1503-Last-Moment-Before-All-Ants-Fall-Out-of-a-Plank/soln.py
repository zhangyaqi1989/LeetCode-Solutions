class Solution:
    def getLastMoment(self, n: int, left: List[int], right: List[int]) -> int:
        ans = 0
        for l in left:
            ans = max(l, ans)
        for r in right:
            ans = max(ans, n - r)
        return ans
