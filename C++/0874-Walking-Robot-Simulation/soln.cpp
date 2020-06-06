class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        set<pair<int, int>> obs;
        for(auto & ob : obstacles) {
            obs.insert({ob[0], ob[1]});
        }
        int ans = 0;
        int x = 0, y = 0;
        int idx = 0;
        for(int command : commands) {
            if (command == -2) {
                idx = updateIdx(idx, -1);
            } else if (command == -1) {
                idx = updateIdx(idx, 1);
            } else {
                auto p = dirs[idx];
                int dx = p.first, dy = p.second;
                for(int i = 0; i < command; ++i) {
                    x += dx;
                    y += dy;
                    if (obs.find({x, y}) != obs.end()) {
                        x -= dx;
                        y -= dy;
                        break;
                    } else {
                        ans = max(ans, x * x + y * y);
                    }           
                }  
            }
        }
        return ans;
    }
    
    int updateIdx(int i, int di) {
        i += di;
        if (i < 0) i += 4;
        return i % 4;
    }
};
