class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) return 0;
        map<pair<int, int>, int> m;
        int ans = 0;
        int nrows = M.size(), ncols = M[0].size();
        for(int i = 0; i < nrows; ++i) {
            for(int j = 0; j < ncols; ++j) {
                // cout << m[{1, i}] << endl;
                m[{1, i}] = (m[{1, i}] + 1) * M[i][j];
                ans = max(ans, m[{1, i}]);
                m[{2, j}] = (m[{2, j}] + 1) * M[i][j];
                ans = max(ans, m[{2, j}]);
                m[{3, i + j}] = (m[{3, i + j}] + 1) * M[i][j];
                ans = max(ans, m[{3, i + j}]);
                m[{4, i - j}] = (m[{4, i - j}] + 1) * M[i][j];
                ans = max(ans, m[{4, i - j}]);
            }
        }
        return ans;
    }
};
