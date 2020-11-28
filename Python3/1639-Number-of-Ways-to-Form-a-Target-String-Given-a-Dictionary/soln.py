class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        MOD = 1000000007
        n = len(target)
        dp = [1] + [0] * n
        for i in range(len(words[0])):
            counter = collections.Counter(w[i] for w in words)
            for j in range(n - 1, -1, -1):
                dp[j + 1] += dp[j] * counter[target[j]] % MOD
        return dp[-1] % MOD
