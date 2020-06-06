int memo[100005];
const int MOD = 1e9 + 7;
class Solution {
public:
    int numberOfArrays(string s, int k) {
        memset(memo, -1, sizeof memo);
        return solve(0, k, s);
    }

private:
    int solve(int idx, int k, const string & s) {
        if(idx == s.length()) return 1;
        if(memo[idx] != -1) return memo[idx];
        long long num = 0;
        int ans = 0;
        for(int nxt = idx; nxt < s.length(); ++nxt) {
            num = num * 10 + s[nxt] - '0';
            if (num <= 0 || num > k || (nxt > idx && s[idx] == '0')) break;
            ans = ( (long long) solve(nxt + 1, k, s) + ans) % MOD;
        }
        return memo[idx] = ans;
    }
};
