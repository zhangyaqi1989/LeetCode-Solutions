class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combo;
        helper(candidates, 0, target, combo, ans);
        return ans;
    }
    
    void helper(vector<int> & cands, int idx, int target, vector<int> & combo, vector<vector<int>>& ans)
    {
        if (target < 0) return;
        if (idx == cands.size() && target != 0) return;
        if (target == 0) ans.push_back(combo);
        for(int i = idx; i < cands.size(); ++i)
        {
            combo.push_back(cands[i]);
            helper(cands, i, target - cands[i], combo, ans);
            combo.pop_back();
        }
    }
};