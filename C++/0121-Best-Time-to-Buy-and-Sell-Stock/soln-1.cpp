class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int ans = 0, n = prices.size();
        int mn_seen = prices[0];
        for(int i = 1; i < n; ++i) {
            ans = max(ans, prices[i] - mn_seen);
            mn_seen = min(mn_seen, prices[i]);
        }
        return ans;
    }
};
