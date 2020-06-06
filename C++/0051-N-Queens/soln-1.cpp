class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        // backtrack
        vector<vector<string>> ans;
        vector<int> Q;
        helper(Q, n, ans);
        return ans;
    }
    
    void helper(vector<int> & Q, int n, vector<vector<string>> & ans) {
        if(Q.size() == n) {
            // cout << "Hello" << endl;
            ans.push_back(toString(Q));
            return;
        }
        int row = Q.size();
        for(int i = 0; i < n; ++i) {
            bool valid = true;
            for(int j = 0; j < row; ++j) {
                if (i == Q[j] || j + Q[j] == i + row || row - i == j - Q[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                Q.push_back(i);
                helper(Q, n, ans);
                Q.pop_back();
            }
        }
    }
    
    vector<string> toString(vector<int> & Q) {
        const int n = Q.size();
        vector<string> ans(n, string(n, '.'));
        for (int i = 0; i < n; ++i) {
            ans[i][Q[i]] = 'Q';
            // cout << ans[i] << endl;
        }
        return ans;
    }
};
