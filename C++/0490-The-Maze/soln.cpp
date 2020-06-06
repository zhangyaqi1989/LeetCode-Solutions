class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        stack<pair<int, int>> s;
        int dis[4] = {0, 0, 1, -1};
        int djs[4] = {1, -1, 0, 0};
        s.push({start[0], start[1]});
        set<pair<int, int>> seen;
        seen.insert({start[0], start[1]});
        int target_i = destination[0], target_j = destination[1];
        while (!s.empty()) {
            auto node = s.top();
            s.pop();
            int i = node.first, j = node.second;
            if (i == target_i && j == target_j) return true;
            for(int k = 0; k < 4; ++k) {
                int di = dis[k], dj = djs[k];
                int newi = i + di, newj = j + dj;
                while (0 <= newi && newi < m && 0 <= newj && newj < n && maze[newi][newj] == 0) {
                    newi += di;
                    newj += dj;
                }
                newi -= di;
                newj -= dj;
                if (i != newi || j != newj) {
                    if (seen.find({newi, newj}) == seen.end()) {
                        seen.insert({newi, newj});
                        s.push({newi, newj});
                    }
                    
                }
            }
        }
        return false;
    }
};
