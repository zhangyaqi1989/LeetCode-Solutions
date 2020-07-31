class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        int h = A.size(), w = A[0].size();
        vector<int> scores(h * w, -1);
        priority_queue<pair<int, int>> frontier;
        frontier.push({A[0][0], 0});
        scores[0] = A[0][0];
        int dirs[] = {1, 0, -1, 0, 1};
        vector<bool> processed(h * w, false);
        int target = h * w - 1;
        while(!frontier.empty()) {
            auto [score, idx] = frontier.top();
            frontier.pop();
            if(idx == target) return score;
            if(processed[idx]) continue;
            processed[idx] = true;
            int r = idx / w, c = idx % w;
            for(int k = 0; k < 4; ++k) {
                int dr = dirs[k], dc = dirs[k + 1];
                int nr = r + dr, nc = c + dc;
                if(0 <= nr && nr < h && 0 <= nc && nc < w) {
                    int new_score = min(score, A[nr][nc]);
                    int new_idx = nr * w + nc;
                    if(new_score > scores[new_idx]) {
                        scores[new_idx] = new_score;
                        frontier.push({new_score, nr * w + nc});
                    }
                }
            }
        }
        return -1;
    }
};
