class Solution:
    def maxScoreSightseeingPair(self, A: List[int]) -> int:
        ans = float('-inf')
        best_seen = float('-inf')
        for i, num in enumerate(A):
            ans = max(ans, best_seen + num - i)
            best_seen = max(best_seen, i + num)
        return ans
