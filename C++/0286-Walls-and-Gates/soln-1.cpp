class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.empty() || rooms[0].empty()) return;
        const int INF = 2147483647;
        queue<pair<int, int>> front;
        int m = rooms.size(), n = rooms[0].size();
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j) {
                if (rooms[i][j] == 0) front.push({i, j});
            }
        int dis[4] = {0, 0, 1, -1};
        int djs[4] = {1, -1, 0, 0};
        while (!front.empty()) {
            auto p = front.front();
            front.pop();
            int i = p.first, j = p.second;
            for(int k = 0; k < 4; ++k) {
                int di = dis[k];
                int dj = djs[k];
                int newi = i + di, newj = j + dj;
                if (0 <= newi && newi < m && newj >= 0 && newj < n && rooms[newi][newj] == INF) {
                    
                    rooms[newi][newj] = rooms[i][j] + 1;
                    front.push({newi, newj});
                    
                }
            }
        }
    }
};
