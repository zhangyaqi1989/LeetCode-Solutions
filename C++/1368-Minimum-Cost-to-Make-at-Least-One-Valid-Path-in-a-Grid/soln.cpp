class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<tuple<int, int, int>> frontier;
        vector<pair<int, int>> dirs = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int dijs[5] = {1, 0, -1, 0, 1};
        frontier.push({0, 0, 0});
        const int kInf = 1e9 + 7;
        vector<vector<int>> costs(m, vector<int>(n, kInf));
        costs[0][0] = 0;
        vector<vector<int>> processed(m, vector<int>(n, false));
        while(!frontier.empty()) {
            auto node = frontier.top();
            frontier.pop();
            int cost, r, c;
            tie(cost, r, c) = node;
            if (r == m - 1 && c == n - 1) return costs[r][c];
            if (processed[r][c]) continue;
            processed[r][c] = true;
            cost = -cost;
            int di, dj;
            tie(di, dj) = dirs[grid[r][c]];
            for(int k = 0; k < 4; ++k) {
                int dr = dijs[k], dc = dijs[k + 1];
                int nr = r + dr, nc = c + dc;
                if (0 <= nr && nr < m && 0 <= nc && nc < n) {
                    int weight = 1;
                    if (dr == di && dc == dj) weight = 0;
                    if (costs[nr][nc] > cost + weight) {
                        costs[nr][nc] = cost + weight;
                        frontier.push({-(cost + weight), nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};
