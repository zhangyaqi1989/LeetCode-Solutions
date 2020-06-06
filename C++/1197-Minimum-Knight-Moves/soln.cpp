class Solution {
public:
    int minKnightMoves(int tx, int ty) {
        int dxs[8] = {1, 1, -1, -1, 2, 2, -2, -2};
        int dys[8] = {2, -2, 2, -2, 1, -1, 1, -1};
        priority_queue<tuple<int, int, int>> pq;
        pq.push({-hfunc(0, 0, tx, ty), 0, 0});
        map<pair<int, int>, int> costs;
        costs[{0, 0}] = 0;
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int x = get<1>(p), y = get<2>(p);
            int c = costs[{x, y}];
            if (x == tx && y == ty) return c;
            for(int k = 0; k < 8; ++k) {
                int nx = x + dxs[k], ny = y + dys[k];
                auto it = costs.find({nx, ny});
                if (it == costs.end() || it->second > c + 1) {
                    costs[{nx, ny}] = c + 1;
                    pq.push({-hfunc(nx, ny, tx, ty) - c - 1, nx, ny});
                }
            }
        
        }
        return -1;
    }
    
private:
    int hfunc(int x, int y, int tx, int ty) {
        return max(abs(x - tx), abs(y - ty)) / 2;
    }
};
