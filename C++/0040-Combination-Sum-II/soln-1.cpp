class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> combo;
        dfs(target, 0, candidates, combo, ans);
        return ans;
    }
    
    void dfs(int target, int idx, vector<int> & candidates, vector<int> & combo, vector<vector<int>> & ans) {
        if (target == 0) ans.push_back(combo);
        else if (target > 0) {
            for(int i = idx; i < candidates.size(); ++i) {
                if (i > idx && candidates[i] == candidates[i - 1]) continue;
                combo.push_back(candidates[i]);
                dfs(target - candidates[i], i + 1, candidates, combo, ans);
                combo.pop_back();
            }
        }
    }
};
