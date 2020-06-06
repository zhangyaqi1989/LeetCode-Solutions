class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // fewest number of coins to make up the amount
        const int INF = 1E9;
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;
        for(int i = 1; i <= amount; ++i) 
            for(int coin : coins) {
                if (i >= coin)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        return dp.back() == INF ? -1 : dp.back();
    }
};
