class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ans;
        vector<int> factors;
        helper(n, 2, factors, ans);
        return ans;
    }
    
    void helper(int n, int num, vector<int>& factors, vector<vector<int>> & ans) {
        int i = num;
        while (i * i <= n) {
            if (n % i == 0) {
                factors.push_back(i);
                factors.push_back(n / i);
                ans.push_back(factors);
                factors.pop_back();
                helper(n / i, i, factors, ans);
                factors.pop_back();
            }
            ++i;
        }
    }
};
