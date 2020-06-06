class Solution {
public:
    string longestPalindrome(string s) {
        string new_s;
        for(char ch : s) {
            new_s += "#";
            new_s += ch;
        }
        new_s += "#";
        return LongestPalindromeHelper(new_s);
    }
    
private:
    string LongestPalindromeHelper(string s) {
        int c = 0, r = 0;
        const int kN = s.length();
        vector<int> P(kN, 0);
        int best_i = 0, max_len = 0;
        for(int i = 0; i < kN; ++i) {
            int mirror = 2 * c - i;
            if (i < r) {
                P[i] = min(r - i, P[mirror]);
            }
            int lo = i - (P[i] + 1);
            int hi = i + (P[i] + 1);
            while (0 <= lo && hi < kN && s[lo] == s[hi]) {
                P[i] += 1;
                --lo;
                ++hi;
            }
            if (i + P[i] > r) {
                c = i;
                r = i + P[i];
                if (P[i] > max_len) {
                    max_len = P[i];
                    best_i = i;
                }
            }
        }
        string ans;
        for(int j = best_i - max_len + 1; j <= best_i + max_len; j += 2) {
            ans += s[j];
        }
        return ans;
    }
};
