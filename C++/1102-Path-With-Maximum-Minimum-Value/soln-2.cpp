class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        const int kDirs[5] = {0, 1, 0, -1, 0};
        const int kR = A.size(), kC = A[0].size();
        vector<vector<int>> scores(kR, vector<int>(kC, -1));
        priority_queue<tuple<int, int, int>> frontier;
        frontier.push({A[0][0], 0, 0});
        scores[0][0] = A[0][0];
        while (!frontier.empty()) {
            int score, r, c;
            tie(score, r, c) = frontier.top();
            frontier.pop();
            for(int k = 0; k < 4; ++k) {
                int new_r = r + kDirs[k], new_c = c + kDirs[k + 1];
                if (0 <= new_r && new_r < kR && 0 <= new_c && new_c < kC) {
                    int new_score = min(score, A[new_r][new_c]);
                    if (scores[new_r][new_c] < new_score) {
                        scores[new_r][new_c] = new_score;
                        frontier.push({new_score, new_r, new_c});
                    }
                }
            }
        }
        return scores[kR - 1][kC - 1];
    }
};
