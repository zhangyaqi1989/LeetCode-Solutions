class Solution {
public:
    int findRotateSteps(string ring, string key) {
        vector<vector<int>> idxes;
        idxes.resize(26);
        int n = ring.size();
        for(int i = 0; i < n; ++i) {
            idxes[ring[i] - 'a'].push_back(i);
        }
        vector<int> dp(n, 0);
        for(auto i : idxes[key[0] - 'a']) {
            dp[i] = min(i, n - i) + 1;
        }
        int m = key.length();
        char pre = key[0];
        for(int i = 1; i < m; ++i) {
            char ch = key[i];
            for(int j : idxes[ch - 'a']) {
                int temp = INT_MAX;
                for(int k : idxes[pre - 'a']) {
                    if (j >= k) temp = min(temp, dp[k] + min(j - k, k - j + n) + 1);
                    else temp = min(temp, dp[k] + min(k - j, j - k + n) + 1);
                }
                dp[j] = temp;
            }
            pre = ch;
        }
        int ans = INT_MAX;
        for(int j : idxes[pre - 'a']) {
            ans = min(ans, dp[j]);
        }
        return ans;
    }
};
