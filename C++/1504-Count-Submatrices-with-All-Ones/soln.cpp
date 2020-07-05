class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        const int kH = mat.size();
        const int kW = mat[0].size();
        vector<vector<int>> left_ones(kH, vector<int>(kW, 0));
        for(int i = 0; i < kH; ++i) {
            for(int j = 0; j < kW; ++j) {
                if(mat[i][j] == 1) {
                    left_ones[i][j] = (j == 0) ? 1 : (left_ones[i][j - 1] + 1);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < kH; ++i) {
            for(int j = 0; j < kW; ++j) {
                if (mat[i][j] == 1) {
                    int mn_left_ones = left_ones[i][j];
                    int r = i;
                    while(r >= 0 && mat[r][j] == 1) {
                        mn_left_ones = min(left_ones[r][j], mn_left_ones);
                        ans += mn_left_ones;
                        --r;
                    }
                }
            }
        }
        return ans;
    }
};
