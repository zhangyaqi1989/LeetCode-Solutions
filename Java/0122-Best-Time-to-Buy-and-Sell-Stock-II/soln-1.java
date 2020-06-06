class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int ans = 0;
        for(int i = 1; i < n; ++i) {
            ans += prices[i] > prices[i - 1] ? prices[i] - prices[i - 1] : 0;
        }
        return ans;
    }
}
