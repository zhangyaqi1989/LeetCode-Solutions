class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = B[0].size(), nA = A[0].size();
        vector<vector<int>> C(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int temp = 0;
                for(int k = 0; k < nA; ++k) 
                    temp += A[i][k] * B[k][j];
                C[i][j] = temp;
            }
        }
        return C;
    }
};
