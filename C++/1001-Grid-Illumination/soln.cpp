class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        map<int, int> row, col, diag, rdiag;
        vector<int> ans;
        set<pair<int, int>> lights;
        for(auto & lamp : lamps) {
            int x = lamp[0], y = lamp[1];
            lights.insert({x, y});
            ++row[x];
            ++col[y];
            ++diag[x + y];
            ++rdiag[x - y];
        }
        for(auto & query : queries) {
            int x = query[0], y = query[1];
            if (row[x] > 0 || col[y] > 0 || diag[x + y] > 0 || rdiag[x - y] > 0)
                ans.push_back(1);
            else ans.push_back(0);
            for (int dx = -1; dx <= 1; ++dx)
                for(int dy = -1; dy <= 1; ++dy) {
                    if (dx == 0 && dy == 0) continue;
                    int nx = x + dx, ny = y + dy;
                    auto it = lights.find({nx, ny});
                    if (it != lights.end()) {
                        lights.erase(it);
                        --row[nx];
                        --col[ny];
                        --diag[nx + ny];
                        --rdiag[nx - ny];
                    }
                }
        }
        return ans;
    }
};
