class Solution {
public:
    int shortestBridge(vector<vector<int>>& A) {
        // BFS
        int dirs[5] = {0, 1, 0, -1, 0};
        const int kR = A.size(), kC = A[0].size();
        vector<pair<int, int>> frontier;
        vector<vector<bool>> visited(kR, vector<bool>(kC, false));
        bool valid = true;
        for(int i = 0; i < kR; ++i) {
            if (!valid) break;
            for(int j = 0; j < kC; ++j) {
                if (A[i][j] == 1) {
                    stack<pair<int, int>> st;
                    A[i][j] = 0;
                    st.push({i, j});
                    while(!st.empty()) {
                        auto node = st.top();
                        st.pop();
                        int r = node.first, c = node.second;
                        frontier.emplace_back(r, c);
                        visited[r][c] = true;
                        for(int k = 0; k < 4; ++k) {
                            int dr = dirs[k], dc = dirs[k + 1];
                            int new_r = r + dr, new_c = c + dc;
                            if (0 <= new_r && new_r < kR && 0 <= new_c && new_c < kC && A[new_r][new_c] == 1) {
                                A[new_r][new_c] = 0;
                                st.push({new_r, new_c});
                            }
                        }
                    }
                    valid = false;
                    break;
                }
            }
        } //
        int steps = 0;
        while (!frontier.empty()) {
            vector<pair<int, int>> next_level;
            for(auto & p : frontier) {
                int r = p.first, c = p.second;
                if (A[r][c] == 1) return steps - 1;
                for(int k = 0; k < 4; ++k) {
                    int dr = dirs[k], dc = dirs[k + 1];
                    int new_r = r + dr, new_c = c + dc;
                    if (0 <= new_r && new_r < kR && 0 <= new_c && new_c < kC && !visited[new_r][new_c]) {
                        visited[new_r][new_c] = true;
                        next_level.emplace_back(new_r, new_c);
                    }
                }
            }
            swap(frontier, next_level);
            ++steps;
        }
        return -1;
    }
};
