class Solution:
    def bestTeamScore(self, scores: List[int], ages: List[int]) -> int:
        pairs = [(age, score) for age, score in zip(ages, scores)]
        pairs.sort()
        dp = [0] * len(pairs)
        for i, (age, score) in enumerate(pairs):
            dp[i] = score
            for j in range(i):
                if score >= pairs[j][1]:
                    dp[i] = max(dp[i], dp[j] + score)
        return max(dp)
