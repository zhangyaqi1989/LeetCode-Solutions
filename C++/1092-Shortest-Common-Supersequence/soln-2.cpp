class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.length(), n2 = str2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = n1 - 1; i >= 0; --i) {
            for (int j = n2 - 1; j >= 0; --j) {
                if (str1[i] == str2[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        // recover path
        int i = 0, j = 0;
        string sub = "";
        while (sub.length() < dp[0][0]) {
            if (str1[i] == str2[j]) {
                sub += str1[i];
                ++i;
                ++j;
            } else {
                if (dp[i + 1][j] >= dp[i][j]) {
                    ++i;
                } else {
                    ++j;
                }
            }
        }
        i = 0, j = 0;
        int k = 0;
        string ans = "";
        while (k < sub.length()) {
            while (i < n1 && str1[i] != sub[k]) ans += str1[i++];
            while (j < n2 && str2[j] != sub[k]) ans += str2[j++];
            ++i;
            ++j;
            ans += sub[k++];
        }
        ans += str1.substr(i);
        ans += str2.substr(j);
        return ans;
    }
};
