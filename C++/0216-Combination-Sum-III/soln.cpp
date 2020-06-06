class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> cands = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> combo;
        helper(cands, k, 0, n, combo, ans);
        return ans;
    }
    
    void helper(vector<int> & cands, int k, int idx, int left, vector<int> & combo, vector<vector<int>> & ans) {
        if(idx == cands.size()) {
            if (combo.size() == k && left == 0) 
                ans.push_back(combo);
            return;
        }
        if (combo.size() > k || left < 0) return;
        if (combo.size() == k) {
            if(left == 0) ans.push_back(combo);
            return;
        }
        for(int i = idx; i < cands.size(); ++i) {
            combo.push_back(cands[i]);
            helper(cands, k, i + 1, left - cands[i], combo, ans);
            combo.pop_back();
        }
    }
};
