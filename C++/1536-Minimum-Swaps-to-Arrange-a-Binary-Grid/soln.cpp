class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        const int kN = grid.size();
        vector<int> trailing_zeros(kN);
        for(int i = 0; i < kN; ++i) {
            int j = kN - 1;
            while(j >= 0 && grid[i][j] == 0) --j;
            trailing_zeros[i] = kN - j - 1;
        }
        int ans = 0;
        for(int i = 0; i < kN; ++i) {
            int req = kN - i - 1;
            int idx = i;
            while(idx < kN && trailing_zeros[idx] < req) {
                idx += 1;
            }
            if(idx == kN) return -1;
            ans += idx - i;
            while(idx > i) {
                trailing_zeros[idx] = trailing_zeros[idx - 1];
                --idx;
            }
        }
        return ans;
    }
};
