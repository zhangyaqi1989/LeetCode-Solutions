class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // BFS
        const int kR = grid.size(), kC = grid[0].size();
        if (grid[0][0] == 1 || grid[kR - 1][kC - 1] == 1) return -1;
        vector<pair<int, int>> frontier;
        frontier.push_back({0, 0});
        grid[0][0] = 1;
        int steps = 1;
        while (!frontier.empty()) {
            vector<pair<int, int>> next_level;
            for(auto & p : frontier) {
                int r = p.first, c = p.second;
                if (r == kR - 1 && c == kC - 1) return steps;
                for(int dr = -1; dr <= 1; ++dr) {
                    for(int dc = -1; dc <= 1; ++dc) {
                        if (dr == 0 && dc == 0) continue;
                        int new_r = r + dr, new_c = c + dc;
                        if (0 <= new_r && new_r < kR && 0 <= new_c && new_c < kC && grid[new_r][new_c] == 0) {
                            grid[new_r][new_c] = 1;
                            next_level.emplace_back(new_r, new_c);
                        }
                    }
                }
            }
            ++steps;
            swap(frontier, next_level);
        }
        return -1;
    }
};
