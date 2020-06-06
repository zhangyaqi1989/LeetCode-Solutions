class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1) return -1;
        int n = grid.size();
        int costs[102][102];
        memset(costs, -1, sizeof costs);
        queue<pair<int, int>> frontier;
        frontier.push({0, 0});
        int dxs[] = {0,0,1,1,1,-1,-1,-1};
        int dys[] = {1,-1,0,1,-1,0,1,-1};
        costs[0][0] = 1;
        while (!frontier.empty()) {
            int x, y;
            tie(x, y) = frontier.front();
            frontier.pop();
            if (x == n - 1 && y == n - 1) return costs[x][y];
            for(int i = 0; i < 8; ++i) {
                int nx = x + dxs[i], ny = y + dys[i];
                if (0 <= nx && nx < n && 0 <= ny && ny < n && grid[nx][ny] == 0 && (costs[nx][ny] == -1 || (costs[x][y] + 1 < costs[nx][ny]))) {
                    frontier.push({nx, ny});
                    costs[nx][ny] = costs[x][y] + 1;
                }
            }
        }
        return -1;
    }
};
