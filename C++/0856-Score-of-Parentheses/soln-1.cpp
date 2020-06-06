class Solution {
public:
    int scoreOfParentheses(string S) {
        int cnt = 0, ans = 0;
        int n = S.length();
        for(int i = 0; i < n - 1; ++i) {
            if (S.substr(i, 2) == "()")
                ans += (1 << cnt);
            cnt += S[i] == '(' ? 1 : -1;
        }
        return ans;
    }
};
