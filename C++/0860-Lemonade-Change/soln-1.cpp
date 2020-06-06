class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(int bill : bills) {
            if (bill == 5) ++five;
            else if (bill == 10) {
                ++ten;
                if (--five < 0) return false;
            } else {
                int change = 15;
                if (ten > 0) {
                    --ten;
                    change = 5;
                }
                if (five < change / 5) {
                    return false;
                }
                five -= change / 5;
            }
        }
        return true;
    }
};
