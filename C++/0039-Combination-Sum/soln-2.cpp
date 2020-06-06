class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        vector<vector<int>> ans;
        dfs(target, 0, path, candidates, ans);
        return ans;
    }
    
    void dfs(int target, int idx, vector<int> & path, vector<int> & candidates, vector<vector<int>> & ans) {
        if (target == 0) ans.push_back(path);
        else if (target > 0) {
            for(int i = idx; i < candidates.size(); ++i) {
                path.push_back(candidates[i]);
                dfs(target - candidates[i], i, path, candidates, ans);
                path.pop_back();
            }
        }
    }
};
