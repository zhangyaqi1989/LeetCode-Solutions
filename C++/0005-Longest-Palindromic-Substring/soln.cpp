class Solution {
public:
    string longestPalindrome(string s) {
        string S = "";
        for(char ch : s) {
            S += "#";
            S += ch;
        }
        S += "#";
        string temp = manacher(S);
        string ans = "";
        for(char ch : temp) {
            if (ch != '#') ans += ch;
        }
        return ans;
    }
    
    string manacher(string S) {
        int c = 0, r = 0, mx = 0, n = S.length();
        vector<int> P(n, 0);
        string ans = "";
        for(int i = 0; i < n; ++i) {
            int mirror = 2 * c - i;
            if (i < r) {
                P[i] = min(P[mirror], r - i);
            }
            int lo = i - (P[i] + 1);
            int hi = i + (P[i] + 1);
            while (lo >= 0 && hi < n && S[lo] == S[hi]) {
                --lo;
                ++hi;
                ++P[i];
            }
            if (i + P[i] > r) {
                c = i;
                r = i + P[i];
                if (P[i] > mx) {
                    mx = P[i];
                    ans = S.substr(i - P[i], 2 * P[i] + 1);
                }
            }
        }
        return ans;
    }
};
