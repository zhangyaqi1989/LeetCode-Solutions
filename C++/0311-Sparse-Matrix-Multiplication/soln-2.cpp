class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        const int kR = A.size(), kC = B[0].size();
        const int kCA = A[0].size();
        vector<vector<int>> C(kR, vector<int>(kC, 0));
        for(int i = 0; i < kR; ++i) {
            for(int j = 0; j < kCA; ++j) {
                if (A[i][j] == 0) continue;
                for(int c = 0; c < kC; ++c) {
                    C[i][c] += A[i][j] * B[j][c];
                }
            }
        }
        return C;
    }
};
