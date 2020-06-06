class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> ans(n, 0);
        int j = 1, k = 0;
        while(j < n) {
            if (s[j] == s[k]) {
                ans[j] = k + 1;
                ++j;
                ++k;
            } else if (k > 0) {
                k = ans[k - 1];
            } else {
                ++j;
            }
        }
        return ans.back() == 0 ? "" : s.substr(0, ans.back());
    }
};
