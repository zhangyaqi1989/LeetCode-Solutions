class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combi;
        dfs(candidates, target, 0, combi, 0, ans);
        return ans;
    }
    
private:
    void dfs(const vector<int> & candidates, int target, int cur, vector<int> & combi, int idx,
            vector<vector<int>> & ans) {
        if (cur == target) {
            ans.push_back(combi);
        } else if (cur < target) {
            for(int i = idx; i < candidates.size(); ++i) {
                combi.push_back(candidates[i]);
                dfs(candidates, target, cur + candidates[i], combi, i, ans);
                combi.pop_back();
            }
        }
    }
};
