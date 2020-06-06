class Solution {
public:
    int scoreOfParentheses(string S) {
        int cnt = 0, ans = 0;
        int n = S.length();
        for(int i = 0; i < n - 1; ++i) {
            if (S.substr(i, 2) == "()")
                ans += (1 << cnt);
            if (S[i] == '(') ++cnt;
            else --cnt;
        }
        return ans;
    }
};
