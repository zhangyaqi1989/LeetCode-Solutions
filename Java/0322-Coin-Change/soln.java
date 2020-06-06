class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        final int INF = 1000000000;
        for(int i = 1; i <= amount; ++i) {
            dp[i] = INF;
            for(int coin : coins) {
                if (i >= coin) 
                    dp[i] = Math.min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] == INF ? -1 : dp[amount];
    }
}
