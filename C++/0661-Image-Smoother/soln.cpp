class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size(), n = M[0].size();
        vector<vector<int>> ans = M;
        for (int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                int cnt = 0, s = 0;
                for (auto di : {-1, 0, 1})
                    for(auto dj : {-1, 0, 1}) {
                        if (i + di >= 0 && i + di < m && j + dj >= 0 && j + dj < n) {
                            s += M[i + di][j + dj];
                            cnt++;
                        }
                    }
                ans[i][j] = s / cnt;
            }
        return ans;
    }
};