class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0, hi = 0;
        for(char ch : s) {
            if (ch == '(') {
                ++lo;
                ++hi;
            } else if (ch == '*') {
                --lo;
                ++hi;
            } else {
                --lo;
                --hi;
            }
            lo = max(0, lo);
            if (hi < 0) return false;
        }
        return lo == 0;
    }
};
