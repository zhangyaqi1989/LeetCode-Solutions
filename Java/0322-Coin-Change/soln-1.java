class Solution {
    public int coinChange(int[] coins, int amount) {
        int [] dp = new int [amount + 1];
        Arrays.sort(coins);
        for(int i = 1; i <= amount; ++i) dp[i] = amount + 1;
        for(int i = 1; i <= amount; ++i) {
            for(int coin : coins) {
                if (i >= coin) dp[i] = Math.min(dp[i], dp[i - coin] + 1);
                else break;
            }
        }
        // for(int num : dp) System.out.println(num);
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
}
