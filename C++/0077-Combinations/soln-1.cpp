class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> comb;
        helper(k, n, comb, ans);
        return ans;
    }
    
    void helper(int k, int n, vector<int> & comb, vector<vector<int>> & ans) {
        if (comb.size() == k) ans.push_back(comb);
        else {
            int start = comb.empty() ? 1 : comb.back() + 1;
            for(int i = start; i <= n; ++i) {
                comb.push_back(i);
                helper(k, n, comb, ans);
                comb.pop_back();
            }
        }
    }
};
