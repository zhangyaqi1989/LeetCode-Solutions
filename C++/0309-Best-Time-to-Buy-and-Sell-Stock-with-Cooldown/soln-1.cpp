class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // hold, cool, free
        if (prices.empty()) return 0;
        const int kN = prices.size();
        int best_cool = INT_MIN, best_hold = -prices[0], best_free = 0;
        for(int i = 1; i < kN; ++i) {
            int price = prices[i];
            int new_best_hold = max(best_hold, best_free - price);
            int new_best_cool = best_hold + price;
            int new_best_free = max(best_free, best_cool);
            best_hold = new_best_hold;
            best_cool = new_best_cool;
            best_free = new_best_free;
        }
        return max(best_cool, best_free);
    }
};
