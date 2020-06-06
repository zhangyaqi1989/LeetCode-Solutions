class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        vector<vector<int>> trees;
        int m = forest.size(), n = forest[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (forest[i][j] > 1) trees.push_back({forest[i][j], i, j});
            }
        }
        sort(trees.begin(), trees.end());
        int r = 0, c = 0;
        int ans = 0;
        for(auto & p : trees) {
            int nr = p[1], nc = p[2];
            int steps = bfs(forest, {r, c}, {nr, nc});
            // cout << steps << endl;
            if (steps == -1) return -1;
            ans += steps;
            r = nr, c = nc;
        }
        return ans;
    }
    
    int bfs(vector<vector<int>> & forest, vector<int> start, vector<int> end) {
        if (start[0] == end[0] && start[1] == end[1]) return 0;
        int m = forest.size(), n = forest[0].size();
        int visited[m][n];
        memset(visited, 0, sizeof visited);
        queue<pair<int, int>> frontier;
        frontier.push({start[0], start[1]});
        int step = 0;
        visited[start[0]][start[1]] = 1;
        int dirs[5] = {1, 0, -1, 0, 1};
        while (!frontier.empty()) {
            ++step;
            int size = frontier.size();
            for(int i = 0; i < size; ++i) {
                int r = frontier.front().first, c = frontier.front().second;
                frontier.pop();
                for(int k = 0; k < 4; ++k) {
                    int nr = r + dirs[k], nc = c + dirs[k + 1];
                    if (nr == end[0] && nc == end[1]) return step;
                    if (0 <= nr && nr < m && 0 <= nc && nc < n && !visited[nr][nc] && forest[nr][nc] != 0) {
                        visited[nr][nc] = 1;
                        frontier.push({nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};
