class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combo;
        sort(candidates.begin(), candidates.end());
        helper(candidates, combo, 0, target, ans);
        return ans;
    }
    
    void helper(vector<int> & candidates, vector<int> & combo, int idx, int left, vector<vector<int>> & ans) {
        if (left < 0) return;
        if (idx == candidates.size()) {
            if (left == 0) ans.push_back(combo);
            return;
        }
        if (left == 0) {
            ans.push_back(combo);   
        } else {
            for (int i = idx; i < candidates.size(); ++i) {
                if (i > idx && candidates[i] == candidates[i - 1]) continue;
                combo.push_back(candidates[i]);
                helper(candidates, combo, i + 1, left - candidates[i], ans);
                combo.pop_back();
            }
        }
    }
};
