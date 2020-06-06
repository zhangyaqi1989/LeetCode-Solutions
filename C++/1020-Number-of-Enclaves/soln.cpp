class Solution {
public:
    int numEnclaves(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    dfs(i, j, A);
                }
            }
        }
        int cnt = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (A[i][j] == 1) ++cnt;
            }
        }
        return cnt;
        
    }
    
    void dfs(int i, int j, vector<vector<int>> & A) {
        if (i >= 0 && i < A.size() && j >= 0 && j < A[0].size() && A[i][j] == 1) {
            A[i][j] = 0;
            dfs(i - 1, j, A);
            dfs(i + 1, j, A);
            dfs(i, j - 1, A);
            dfs(i, j + 1, A);
        }
    }
};
