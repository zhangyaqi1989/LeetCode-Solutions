class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;
        for(int bill : bills) {
            if (bill == 5) {
                ++fives;
            } else if (bill == 10) {
                if (fives == 0) return false;
                else --fives;
                ++tens;
            } else {
                int left = 15;
                if (tens > 0) {
                    --tens;
                    left -= 10;
                }
                if (left > fives * 5) return false;
                fives -= left / 5;
            }
        }
        return true;
    }
};