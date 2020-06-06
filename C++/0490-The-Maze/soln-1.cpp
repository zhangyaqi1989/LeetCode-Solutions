class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& dst) {
        const int kDirs[5] = {0, 1, 0, -1, 0};
        const int kR = maze.size(), kC = maze[0].size();
        vector<vector<bool>> visited(kR, vector<bool>(kC, false));
        stack<vector<int>> frontier;
        frontier.push(start);
        visited[start[0]][start[1]] = true;
        while (!frontier.empty()) {
            auto node = frontier.top();
            frontier.pop();
            int r = node[0], c = node[1];
            if (node == dst) return true;
            for(int k = 0; k < 4; ++k) {
                int dr = kDirs[k], dc = kDirs[k + 1];
                int new_r = r + dr, new_c = c + dc;
                while (0 <= new_r && new_r < kR && 0 <= new_c && new_c < kC && maze[new_r][new_c] != 1) {
                    new_r += dr;
                    new_c += dc;
                } 
                new_r -= dr;
                new_c -= dc;
                if (!visited[new_r][new_c]) {
                    visited[new_r][new_c] = true;
                    vector<int> new_node = {new_r, new_c};
                    frontier.push(new_node);
                }
            }
        }
        return false;
    }
};
