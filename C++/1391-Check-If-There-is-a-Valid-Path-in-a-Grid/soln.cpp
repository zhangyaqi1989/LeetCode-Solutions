class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // How to represent the graph
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        //  0
        // 3 1
        //  2
        vector<vector<int>> num2dir = {{0, 0}, {3, 1}, {0, 2}, {3, 2}, {1, 2}, {0, 3}, {0, 1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        stack<pair<int, int>> frontier;
        frontier.push({0, 0});
        visited[0][0] = true;
        while(!frontier.empty()) {
            int r, c;
            tie(r, c) = frontier.top();
            // cout << r << " " << c << endl;
            frontier.pop();
            if (r == m - 1 && c == n - 1) return true;
            for(int idx : num2dir[grid[r][c]]) {
                int dr = dirs[idx][0], dc = dirs[idx][1];
                int nr = r + dr, nc = c + dc;
                if (0 <= nr && nr < m && 0 <= nc && nc < n) {
                    // cout << " H " << nr << " " << nc << endl;
                    int nv = grid[nr][nc];
                    // cout << num2dir[nv][0] << " " << num2dir[nv][1] << endl;
                    if (((dirs[num2dir[nv][0]][0] == -dr && dirs[num2dir[nv][0]][1] == -dc) || (dirs[num2dir[nv][1]][0] == -dr && dirs[num2dir[nv][1]][1] == -dc)) && !visited[nr][nc]) {
                        visited[nr][nc] = true;
                        frontier.push({nr, nc});
                    }
                }
            }
        }
        return false;
    }
};


