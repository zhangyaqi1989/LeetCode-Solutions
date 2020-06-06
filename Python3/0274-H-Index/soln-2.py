class Solution:
    def hIndex(self, citations: List[int]) -> int:
        ans = 0
        for c in sorted(citations, reverse=True):
            if c > ans:
                ans += 1
            else:
                return ans
        return ans
