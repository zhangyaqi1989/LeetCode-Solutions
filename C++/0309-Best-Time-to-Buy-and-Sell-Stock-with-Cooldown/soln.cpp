class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // hold, free to buy, cool
        // init: hold = INT_MIN, cool = INT_MIN, free to buy = 0
        // transition: new_hold = max(hold, free - price)
        // new_cool = hold + price
        // new_free = max(free, cool)
        int hold = INT_MIN, cool = INT_MIN, free_buy = 0;
        for(int price : prices) {
            int new_hold = max(hold, free_buy - price);
            int new_cool = hold + price;
            int new_free_buy = max(free_buy, cool);
            hold = new_hold;
            cool = new_cool;
            free_buy = new_free_buy;
        }
        return max(cool, free_buy);
    }
};
