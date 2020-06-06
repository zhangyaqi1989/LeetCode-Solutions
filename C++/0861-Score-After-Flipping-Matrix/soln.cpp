class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        bool row_flip[m];
        for(int i = 0; i < m; ++i) {
            if (A[i][0] == 0) row_flip[i] = true;
            else row_flip[i] = false;
            // cout << row_flip[i] << endl;
        }
        int ans = 0;
        for(int j = 0; j < n; ++j) {
            int ones = 0;
            for(int i = 0; i < m; ++i) {
                if((row_flip[i] && A[i][j] == 0) || (!row_flip[i] && A[i][j] == 1)) ++ones;
            }
            ans = ans * 2 + max(ones, m - ones);
            // cout << ans << endl;
        }
        return ans;
    }
};
