class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        priority_queue<tuple<int, int, int>> frontier;
        frontier.push({-grid[0][0], 0, 0});
        int dirs[5] = {1, 0, -1, 0, 1};
        grid[0][0] = -1;
        while (!frontier.empty()) {
            int level, i, j;
            tie(level, i, j) = frontier.top();
            level = -level;
            frontier.pop();
            if (i == N - 1 && j == N - 1) {
                return level;
            }
            for(int k = 0; k < 4; ++k) {
                int ni = i + dirs[k], nj = j + dirs[k + 1];
                if (0 <= ni && ni < N && 0 <= nj && nj < N && grid[ni][nj] != -1) {
                    frontier.push({-max(level, grid[ni][nj]), ni, nj});
                    grid[ni][nj] = -1;
                }
            }
        }
        return -1;
    }
};
