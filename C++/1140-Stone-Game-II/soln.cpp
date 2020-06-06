class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        vector<vector<int>> memo(105, vector<int>(105, 0));
        vector<int> prefix = {0};
        for(int stone : piles) prefix.push_back(prefix.back() + stone);
        return dfs(piles, prefix, memo, 0, 1);
    }

    int dfs(vector<int> & piles, vector<int> & prefix, vector<vector<int>> & memo, int lo, int M) {
        if (memo[lo][M] != 0) return memo[lo][M];
        int n = piles.size();
        if (lo == n) return 0;
        // pick lo:i
        int ans = 0;
        for(int i = lo + 1; i <= min(lo + 2 * M, n); ++i) {
            ans = max(ans, prefix[n] - prefix[lo] - dfs(piles, prefix, memo, i, max(M, i - lo)));
        }
        memo[lo][M] = ans;
        return ans;
    }
};
