int dis[4] = {0, 0, 1, -1};
int djs[4] = {1, -1, 0, 0};

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        set<vector<pair<int, int>>> islands;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    vector<pair<int, int>> island;
                    dfs(i, j, grid, island);
                    islands.insert(island);
                }
            }
        return islands.size();
    }

    void dfs(int i0, int j0, vector<vector<int>> & grid, vector<pair<int, int>> & island) {
        stack<pair<int, int>> s;
        s.push({i0, j0});
        grid[i0][j0] = 0;
        int m = grid.size(), n = grid[0].size();
        while(!s.empty()) {
            auto p = s.top();
            int i = p.first, j = p.second;
            island.emplace_back(i - i0, j - j0);
            s.pop();
            for(int d = 0; d < 4; ++d) {
                int newi = i + dis[d], newj = j + djs[d];
                if (newi >= 0 && newi < m && newj >= 0 && newj < n && grid[newi][newj] == 1) {
                    grid[newi][newj] = 0;
                    s.push({newi, newj});
                }
            }
        }
    }
};
