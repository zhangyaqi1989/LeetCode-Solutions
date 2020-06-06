class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        // find a 0 which is farthest to 1
        const int kR = grid.size(), kC = grid[0].size();
        bool visited[kR][kC];
        memset(visited, 0, sizeof visited);
        vector<pair<int, int>> frontier;
        for(int i = 0; i < kR; ++i) {
            for(int j = 0; j < kC; ++j) {
                if (grid[i][j] == 1) {
                    visited[i][j] = true;
                    frontier.emplace_back(i, j);
                }
            }
        }
        if (frontier.size() == kR * kC) return -1;
        int steps = 0;
        int dirs[5] = {0, 1, 0, -1, 0};
        while(!frontier.empty()) {
            vector<pair<int, int>> next_level;
            for(auto & pos : frontier) {
                int i = pos.first, j = pos.second;
                for(int k = 0; k < 4; ++k) {
                    int di = dirs[k], dj = dirs[k + 1];
                    int new_i = i + di, new_j = j + dj;
                    if (0 <= new_i && new_i < kR && 0 <= new_j && new_j < kC && !visited[new_i][new_j]) {
                        visited[new_i][new_j] = true;
                        next_level.emplace_back(new_i, new_j);
                    }
                }
            }
            swap(frontier, next_level);
            ++steps;
        }
        return steps - 1;
    }
};
