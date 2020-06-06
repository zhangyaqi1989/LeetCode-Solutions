class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int r = r0, c = c0;
        int step = 0;
        int cnt = 0, n = R * C;
        int face = 0;
        int drs[4] = {0, 1, 0, -1};
        int dcs[4] = {1, 0, -1, 0};
        vector<vector<int>> ans;
        while (ans.size() < n) {
            if (cnt % 2 == 0) {
                ++step;
            }
            ++cnt;
            int dr = drs[face], dc = dcs[face];
            face = (face + 1) % 4;
            for(int i = 0; i < step; ++i) {
                if (0 <= r && r < R && 0 <= c && c < C) {
                    ans.push_back({r, c});
                }
                r += dr;
                c += dc;
            }
        }
        return ans;
        
    }
};
