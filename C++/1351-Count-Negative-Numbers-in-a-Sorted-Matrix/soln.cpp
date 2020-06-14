class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int h = grid.size(), w = grid[0].size();
        // for each row, compute first negative index
        int cnt = 0;
        for(int i = 0; i < h; ++i) {
            int lo = 0, hi = w;
            while(lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (grid[i][mid] >= 0) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
            cnt += w - hi;
        }
        return cnt;
    }
};
