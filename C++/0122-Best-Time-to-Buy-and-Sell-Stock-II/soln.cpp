class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        for(int i = 1; i < n; ++i) {
            ans += prices[i] > prices[i - 1] ? prices[i] - prices[i - 1] : 0;
        }
        return ans;
    }
};
