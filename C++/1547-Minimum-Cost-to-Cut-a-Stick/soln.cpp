
int dp[105][105] = {0};

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        memset(dp, 0, sizeof dp);
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        return Dfs(cuts, 0, cuts.size() - 1);
    }
    
    
private:
    int Dfs(const vector<int> & cuts, int lo, int hi) {
        if(hi - lo <= 1) {
            return 0;
        }
        if(dp[lo][hi]) return dp[lo][hi];
        int ans = INT_MAX;
        for(int k = lo + 1; k < hi; ++k) {
            ans = min(ans, Dfs(cuts, lo, k) + Dfs(cuts, k, hi));
        }
        return dp[lo][hi] = ans + cuts[hi] - cuts[lo];
    }
};
