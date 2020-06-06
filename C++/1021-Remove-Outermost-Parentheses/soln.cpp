class Solution {
public:
    string removeOuterParentheses(string S) {
        int cnt = 0;
        string ans = "";
        int n = S.length();
        int lo = 0;
        for(int i = 0; i < n; ++i) {
            char ch = S[i];
            if (ch == '(') {
                ++cnt;
            } else {
                --cnt;
                if (cnt == 0) {
                    ans += S.substr(lo + 1, i - (lo + 1));
                    lo = i + 1;
                }
            }
        }
        return ans;
    }
};
