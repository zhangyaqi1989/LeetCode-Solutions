class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        const int kDirs[5] = {0, -1, 0, 1, 0};
        const int kR = A.size(), kC = A[0].size();
        vector<vector<int>> ds(kR, vector<int>(kC, -1));
        vector<vector<bool>> enqueue(kR, vector<bool>(kC, false));
        queue<pair<int, int>> frontier;
        frontier.push({0, 0});
        ds[0][0] = A[0][0];
        enqueue[0][0] = true;
        while (!frontier.empty()) {
            auto node = frontier.front();
            frontier.pop();
            int r = node.first, c = node.second;
            enqueue[r][c] = false;
            for(int k = 0; k < 4; ++k) {
                int new_r = r + kDirs[k], new_c = c + kDirs[k + 1];
                if (0 <= new_r && new_r < kR && 0 <= new_c && new_c < kC) {
                    int new_score = min(ds[r][c], A[new_r][new_c]);
                    if (new_score > ds[new_r][new_c]) {
                        ds[new_r][new_c] = new_score;
                        if (!enqueue[new_r][new_c]) {
                            frontier.push({new_r, new_c});
                            enqueue[new_r][new_c] = true;
                        }
                    }
                }
            }
        }
        return ds[kR - 1][kC - 1];
    }
};
