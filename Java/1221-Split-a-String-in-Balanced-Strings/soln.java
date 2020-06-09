class Solution {
public:
    int balancedStringSplit(string s) {
        int nopens = 0, cnt = 0;
        for(char ch : s) {
            nopens += (ch == 'L' ? 1 : -1);
            cnt += nopens == 0;
        }
        return cnt;
    }
};
