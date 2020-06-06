class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int m = grid.size(), n = grid[0].size();
        int kills[m][n];
        memset(kills, 0, sizeof(kills));
        for(int i = 0; i < m; ++i) {
            int left = 0;
            for(int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') kills[i][j] += left;
                else if (grid[i][j] == 'W') left = 0;
                else ++left;
            }
            int right = 0;
            for(int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == '0') kills[i][j] += right;
                else if (grid[i][j] == 'W') right = 0;
                else ++right;
            }
        }
        for(int j = 0; j < n; ++j) {
            int up = 0;
            for(int i = 0; i < m; ++i) {
                if (grid[i][j] == '0') kills[i][j] += up;
                else if (grid[i][j] == 'W') up = 0;
                else ++up;
            }
            
            int down = 0;
            for(int i = m - 1; i >= 0; --i) {
                if (grid[i][j] == '0') kills[i][j] += down;
                else if (grid[i][j] == 'W') down = 0;
                else ++down;
            }
        }
        int mx = INT_MIN;
        for(auto & row : kills) {
            for(auto & val : row) {
                if (val > mx) mx = val;
            }
        }
        return mx;
    }
};
