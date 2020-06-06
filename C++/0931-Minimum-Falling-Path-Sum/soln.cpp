class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int djs[3] = {-1, 1};
        vector<int> ans = A[0];
        int m = A.size(), n = A[0].size();
        for(int i = 1; i < m; ++i) {
            vector<int> temp(ans.begin(), ans.end());
            for(int j = 0; j < n; ++j) {
                for(int dj : djs) {
                    if (j + dj >= 0 && j + dj < n && temp[j] > ans[j + dj])
                        temp[j] = ans[j + dj];
                        
                }
                temp[j] += A[i][j];
            }
            swap(temp, ans);
        }
        return *min_element(ans.begin(), ans.end());
    }
};
