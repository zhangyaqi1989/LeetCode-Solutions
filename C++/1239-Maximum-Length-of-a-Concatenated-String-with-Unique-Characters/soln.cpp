class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> ints;
        for(const string & s : arr) {
            int mask = 0;
            bool valid = true;
            for(const char ch : s) {
                if (mask & (1 << (ch - 'a'))) {
                    valid = false;
                    break;
                } else mask |= (1 << (ch - 'a'));
            }
            if (valid) ints.push_back(mask);
        }
        vector<int> dp = {0};
        int mx = 0;
        for(int num : ints) {
            const int sz = dp.size();
            for(int i = 0; i < sz; ++i) {
                if ((dp[i] & num) == 0) {
                    mx = max(mx, __builtin_popcount(dp[i] | num));
                    dp.push_back(dp[i] | num);
                }
            }
        }
        return mx;
    }
};
