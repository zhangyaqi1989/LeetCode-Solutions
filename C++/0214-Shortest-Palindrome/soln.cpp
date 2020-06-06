class Solution {
public:
    string shortestPalindrome(string s) {
        string rs(s);
        reverse(rs.begin(), rs.end());
        string ns = s + '#' + rs;
        int n = ns.length();
        vector<int> fail(n, 0);
        int j = 1, k = 0;
        while (j < n) {
            if (ns[j] == ns[k]) {
                fail[j] = k + 1;
                ++j;
                ++k;
            } else if (k > 0) {
                k = fail[k - 1];
            } else {
                ++j;
            }
        }
        string ans(s);
        string add_s = s.substr(fail.back());
        reverse(add_s.begin(), add_s.end());
        return add_s + s;
    }
};
