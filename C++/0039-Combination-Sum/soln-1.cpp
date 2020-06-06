class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combo;
        helper(candidates, combo, 0, target, ans);
        return ans;
    }
    
    void helper(vector<int> & candidates, vector<int> & combo, int idx, int left, vector<vector<int>> & ans) {
        if (left < 0) return;
        if (left == 0) {
            ans.push_back(combo);
        } else {
            for(int i = idx; i < candidates.size(); ++i) {
                combo.push_back(candidates[i]);
                helper(candidates, combo, i, left - candidates[i], ans);
                combo.pop_back();
            }
        }
    }
};
