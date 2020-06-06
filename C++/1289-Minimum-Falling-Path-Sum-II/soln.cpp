class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        const int kInf = 500000;
        const int kM = arr.size(), kN = arr[0].size();
        for(int i = 1; i < kM; ++i) {
            int mn = kInf;
            int mn_idx = -1;
            int second_mn = kInf;
            for(int j = 0; j < kN; ++j) {
                if (arr[i - 1][j] <= mn) {
                    second_mn = mn;
                    mn = arr[i - 1][j];
                    mn_idx = j;
                } else if (arr[i - 1][j] < second_mn) {
                    second_mn = arr[i - 1][j];
                }
            }
            for(int j = 0; j < kN; ++j) {
                arr[i][j] += (j == mn_idx) ? second_mn : mn;
            }
        }
        return *min_element(arr.back().begin(), arr.back().end());
    }
};
