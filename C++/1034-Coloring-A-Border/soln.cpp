class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        if (color == grid[r0][c0]) return grid;
        int R = grid.size(), C = grid[0].size();
        int orin_color = grid[r0][c0];
        set<pair<int, int>> colored;
        stack<pair<int, int>> stk;
        stk.push({r0, c0});
        grid[r0][c0] = color;
        colored.insert({r0, c0});
        int dirs[] = {1, 0, -1, 0, 1};
        while (!stk.empty()) {
            auto node = stk.top();
            stk.pop();
            int r = node.first, c = node.second;
            for (int k = 0; k < 4; ++k) {
                int newr = r + dirs[k], newc = c + dirs[k + 1];
                if (0 <= newr && newr < R && 0 <= newc && newc < C && grid[newr][newc] == orin_color) {
                    grid[newr][newc] = color;
                    stk.push({newr, newc});
                    colored.insert({newr, newc});
                }
            }
        }
        vector<pair<int, int>> inner;
        for(auto & p : colored) {
            int is_inner = true;
            int r = p.first, c = p.second;
            for(int k = 0; k < 4; ++k) {
                int newr = r + dirs[k], newc = c + dirs[k + 1];
                if (newr < 0 || newr >= R || newc < 0 || newc >= C || !colored.count({newr, newc})) {
                    is_inner = false;
                    break;
                }
            }
            if (is_inner) inner.push_back({r, c});
        }
        for(auto & p : inner) {
            grid[p.first][p.second] = orin_color;
        }
        return grid;
    }
};
