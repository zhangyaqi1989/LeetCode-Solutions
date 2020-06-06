class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        // any row and any col
        // 0011
        // 1010
        // 1100
        int h = A.size(), w = A[0].size();
        vector<int> cols(w, 0);
        for(int i = 0; i < h; ++i) {
            for(int j = w - 1; j >= 0; --j) {
                if(A[i][0] == 0) A[i][j] ^= 1;
                cols[j] += A[i][j];
            }
        }
        int ans = 0;
        for(int j = 0; j < w; ++j) {
            ans += (1 << (w - 1 - j)) * (max(h - cols[j], cols[j]));
        }
        return ans;
    }
};
