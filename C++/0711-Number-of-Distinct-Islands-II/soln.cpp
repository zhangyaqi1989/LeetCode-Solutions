class Solution {
public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
        set<vector<pair<int, int>>> islands;
        const int R = grid.size(), C = grid[0].size();
        for(int r = 0; r < R; ++r) {
            for(int c = 0; c < C; ++c) {
                if (grid[r][c] == 1) {
                    vector<pair<int, int>> island;
                    dfs(r, c, grid, island);
                    islands.insert(normalize(island));
                }
            }
        }
        return islands.size();
    }
    
private:
    void dfs(int r, int c, vector<vector<int>> & grid, vector<pair<int, int>> & island) {
        if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == 1) {
            grid[r][c] = 0;
            island.emplace_back(r, c);
            dfs(r - 1, c, grid, island);
            dfs(r + 1, c, grid, island);
            dfs(r, c - 1, grid, island);
            dfs(r, c + 1, grid, island);
        }
    }
    
    vector<pair<int, int>> normalize(const vector<pair<int, int>> & island) {
        vector<vector<pair<int, int>>> s(8);
        for(const auto & p : island) {
            int x = p.first, y = p.second;
            s[0].emplace_back(x, y);
            s[1].emplace_back(-x, y);
            s[2].emplace_back(x, -y);
            s[3].emplace_back(-x, -y);
            s[4].emplace_back(y, x);
            s[5].emplace_back(-y, x);
            s[6].emplace_back(y, -x);
            s[7].emplace_back(-y, -x);
        }
        for(auto & item : s) sort(item.begin(), item.end());
        for(auto & item : s) {
            const int n = item.size();
            int x0 = item[0].first, y0 = item[0].second;
            for(int i = 0; i < n; ++i) {
                item[i].first -= x0;
                item[i].second -= y0;
            }
        }
        sort(s.begin(), s.end());
        return s[0];
    }
};
