class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        const int n = prices.size();
        if (n < 2) return 0;
        int best_hold = -prices[0];
        int best_nohold = 0;
        int profit = 0;
        for(int i = 1; i < n; ++i) {
            int new_best_hold = max(best_hold, best_nohold - prices[i]);
            int new_best_nohold = max(best_nohold, best_hold + prices[i] - fee);
            best_hold = new_best_hold;
            best_nohold = new_best_nohold;
            profit = max(profit, max(best_hold, best_nohold));
        }
        return profit;
        
    }
};
