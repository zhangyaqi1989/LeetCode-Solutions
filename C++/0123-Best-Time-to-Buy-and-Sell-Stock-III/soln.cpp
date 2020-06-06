class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold1 = INT_MIN, free1 = 0, hold2 = INT_MIN, free2 = INT_MIN;
        for(int price : prices) {
            free1 = max(free1, hold1 + price);
            hold1 = max(hold1, -price);
            free2 = max(free2, hold2 + price);
            hold2 = max(hold2, free1 - price);
        }
        return max(free1, free2);
    }
};
