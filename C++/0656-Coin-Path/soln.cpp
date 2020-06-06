class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        vector<int> ans;
        if (A.empty() || A.back() == -1) return ans;
        int n = A.size();
        vector<int> nxt(n, -1);
        const int INF = 1000000;
        vector<int> dp(n, INF);
        dp.back() = A.back();
        for(int i = n - 2; i >= 0; --i) {
            if (A[i] == -1) continue;
            for(int j = i + 1; j < min(n, i + B + 1); ++j) {
                if (dp[i] > dp[j] + A[i]) {
                    dp[i] = dp[j] + A[i];
                    nxt[i] = j;
                }
            }
        }
        if(dp[0] == INF) return ans;
        int i = 0;
        while (nxt[i] != -1) {
            ans.push_back(i + 1);
            i = nxt[i];
        }
        ans.push_back(n);
        return ans;
    }
};
