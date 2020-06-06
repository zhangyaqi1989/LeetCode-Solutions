class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if (forest.empty() || forest[0].empty()) return 0;
        const int kR = forest.size(), kC = forest[0].size();
        vector<pair<int, int>> targets;
        for(int r = 0; r < kR; ++r) {
            for(int c = 0; c < kC; ++c) {
                if (forest[r][c] > 1) targets.emplace_back(r, c);
            }
        }
        sort(targets.begin(), targets.end(), [&](const pair<int, int> & t1, const pair<int, int> & t2) {
            return forest[t1.first][t1.second] < forest[t2.first][t2.second];
        });
        int walk = 0;
        pair<int, int> cur = {0, 0};
        for(const auto & target : targets) {
            forest[target.first][target.second] = 1;
            int d = Bfs(forest, cur, target);
            if (d == -1) return -1;
            walk += d;
            cur = target;
        }
        return walk;
    }
    
private:
    // return -1 when no path between source and target
    int Bfs(const vector<vector<int>> & forest, const pair<int, int> & source, const pair<int, int> & target) {
        const int kR = forest.size(), kC = forest[0].size();
        int dirs[5] = {0, 1, 0, -1, 0};
        vector<pair<int, int>> frontier = {source};
        int visited[kR][kC];
        memset(visited, 0, sizeof visited);
        visited[source.first][source.second] = true;
        int steps = 0;
        while(!frontier.empty()) {
            vector<pair<int, int>> next_level;
            for(const auto pos : frontier) {
                if (pos == target) return steps;
                int r = pos.first, c = pos.second;
                for(int k = 0; k < 4; ++k) {
                    int dr = dirs[k], dc = dirs[k + 1];
                    int new_r = r + dr, new_c = c + dc;
                    if (0 <= new_r && new_r < kR && 0 <= new_c && new_c < kC && forest[new_r][new_c] != 0 && !visited[new_r][new_c]) {
                        next_level.emplace_back(new_r, new_c);
                        visited[new_r][new_c] = true;
                    }
                }
            }
            swap(frontier, next_level);
            ++steps;
        }
        return -1;
    }
};
