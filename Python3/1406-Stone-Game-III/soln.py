class Solution:
    def stoneGameIII(self, stones: List[int]) -> str:
        n = len(stones)
        dp = [-math.inf] * (n + 1)
        prefix_sum = [0]
        for num in reversed(stones):
            prefix_sum.append(prefix_sum[-1] + num)
        prefix_sum = prefix_sum[::-1]
        # print(prefix_sum)
        dp[n] = 0
        for i in range(n - 1, -1, -1):
            pick = 0
            best = -math.inf
            for j in range(i, min(i + 3, n)):
                pick += stones[j]
                cur = pick + prefix_sum[j + 1] - dp[j + 1]
                best = max(best, cur)
            dp[i] = best
        total = sum(stones)
        alice = dp[0]
        bob = total - alice
        # print(dp)
        # print(dp[0])
        if alice == bob:
            return "Tie"
        elif alice > bob:
            return "Alice"
        else:
            return "Bob"
