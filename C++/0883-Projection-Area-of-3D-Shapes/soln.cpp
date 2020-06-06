class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int side = 0, front = 0, top = 0;
        for(int i = 0; i < m; ++i) {
            int temp = 0;
            for(int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) ++top;
                if (grid[i][j] > temp) temp = grid[i][j];
            }
            side += temp;
        }
        for(int j = 0; j < n; ++j) {
            int temp = 0;
            for(int i = 0; i < m; ++i) {
                if (grid[i][j] > temp) temp = grid[i][j];
            }
            front += temp;
        }
        return side + front + top;
    }
};
