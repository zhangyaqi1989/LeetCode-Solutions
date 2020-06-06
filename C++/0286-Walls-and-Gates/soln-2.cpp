// BFS
// graph: node --> neighbors
// tree is a special graph, connected graph without cycle
// n nodes in tree, then there are n - 1 edges
// V = m * n, E ~ O(V)
// V + E
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty()) return;
        const int WALL = -1;
        const int GATE = 0;
        const int ROOM = (1 << 31) - 1; // INF 2**31
        const int DIRS[5] = {0, 1, 0, -1, 0};
        const int kR = rooms.size(), kC = rooms[0].size();
        vector<pair<int, int>> frontier;
        for(int r = 0; r < kR; ++r) {
            for(int c = 0; c < kC; ++c) {
                if (rooms[r][c] == GATE) frontier.emplace_back(r, c);
            }
        }
        int steps = 0;
        while(!frontier.empty()) {
            vector<pair<int, int>> next_level;
            for(const auto & p : frontier) {
                int r, c;
                tie(r, c) = p;
                for(int k = 0; k < 4; ++k) {
                    int dr = DIRS[k], dc = DIRS[k + 1];
                    int new_r = r + dr, new_c = c + dc;
                    if (0 <= new_r && new_r < kR && 0 <= new_c && new_c < kC && rooms[new_r][new_c] == ROOM) {
                        rooms[new_r][new_c] = steps + 1;
                        next_level.emplace_back(new_r, new_c);
                    }
                }
            }
            swap(next_level, frontier);
            ++steps;
        }
        
    }
};
