class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        memo.clear();
        return dfs(workers, bikes, 0, 0);
    }
    
    int dfs(vector<vector<int>> & workers, vector<vector<int>> & bikes, int idx, int mask) {
        if (idx == workers.size()) return 0;
        auto it = memo.find({idx, mask});
        if (it != memo.end()) return it->second;
        int ans = INT_MAX;
        for(int i = 0; i < bikes.size(); ++i) {
            if ((mask & (1 << i)) == 0) {
                ans = min(ans, abs(workers[idx][0] - bikes[i][0]) + abs(workers[idx][1] - bikes[i][1]) + dfs(workers, bikes, idx + 1, mask | (1 << i)));
            }
        }
        memo[{idx, mask}] = ans;
        return ans;
    }
    
private:
    map<pair<int, int>, int> memo;
};
