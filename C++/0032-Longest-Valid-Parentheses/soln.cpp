class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> unmatches;
        int n = s.length();
        for(int i = 0; i < n; ++i) {
            char ch = s[i];
            if (ch == '(') {
                unmatches.push_back(i);
            } else {
                if (!unmatches.empty() && s[unmatches.back()] == '(') {
                    unmatches.pop_back();
                } else {
                    unmatches.push_back(i);
                }
            }
        }
        unmatches.push_back(n);
        int mx = unmatches.front();
        int m = unmatches.size();
        for(int i = 1; i < m; ++i) {
            mx = max(mx, unmatches[i] - unmatches[i - 1] - 1);
        }
        return mx;
    }
};
