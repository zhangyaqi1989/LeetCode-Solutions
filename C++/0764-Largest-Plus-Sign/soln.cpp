class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int grid[N][N];
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                grid[i][j] = min(min(i, j), min(N - 1 - i, N - 1 - j)) + 1;
            }
        }
        for(vector<int> & mine : mines) {
            int r = mine[0], c = mine[1];
            for (int idx = 0; idx < N; ++idx) {
                grid[r][idx] = min(grid[r][idx], abs(idx - c));
                grid[idx][c] = min(grid[idx][c], abs(idx - r));
            }
        }
        int ans = 0;
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                // cout << grid[i][j] << endl;
                ans = max(ans, grid[i][j]);
            }
        }
        return ans;
    }
};
