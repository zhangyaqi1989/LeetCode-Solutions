class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> combo;
        helper(n, k, combo, ans);
        return ans;
    }
    
    void helper(int n, int k, vector<int> & combo, vector<vector<int>> & ans) {
        if (combo.size() == k) {
            ans.push_back(combo);
        } else {
            int start = combo.size() ? combo.back() + 1 : 1;
            for (int i = start; i <= n; ++i) {
                combo.push_back(i);
                helper(n, k, combo, ans);
                combo.pop_back();
            }
        }
    }
};