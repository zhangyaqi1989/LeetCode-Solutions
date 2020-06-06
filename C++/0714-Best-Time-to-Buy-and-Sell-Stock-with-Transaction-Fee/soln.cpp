class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // hold, not hold
        // init: hold = INT_MIN, not_hold = 0
        // transition: new_hold = max(hold, not_hold - price)
        // transition: new_not_hold = max(not_hold, hold + price - fee)
        int hold = -1000000, not_hold = 0;
        for(int price : prices) {
            int new_hold = max(hold, not_hold - price);
            int new_not_hold = max(not_hold, hold + price - fee);
            hold = new_hold;
            not_hold = new_not_hold;
        }
        // cout << hold << " " << not_hold << endl;
        return not_hold;
    }
};
