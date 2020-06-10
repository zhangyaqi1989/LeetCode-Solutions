int dis[4] = {0, 0, 1, -1};
int djs[4] = {1, -1, 0, 0};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> frontier;
        int cnt = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) frontier.push({i, j});
                else if (grid[i][j] == 1) ++cnt;
            }
        int steps = 0;
        while (!frontier.empty()) {
            int size = frontier.size();
            if (cnt == 0) return steps;
            ++steps;
            for(int k = 0; k < size; ++k) {
                auto p = frontier.front();
                frontier.pop();
                int i = p.first, j = p.second;
                for(int c = 0; c < 4; ++c) {
                    int di = dis[c], dj = djs[c];
                    int newi = i + di, newj = j + dj;
                    if (newi >= 0 && newi < m && newj >= 0 && newj < n && grid[newi][newj] == 1) {
                        grid[newi][newj] = 2;
                        frontier.push({newi, newj});
                        --cnt;
                    }
                }
            }
        }
        if (cnt == 0) return steps;
        return -1;
    }
};
