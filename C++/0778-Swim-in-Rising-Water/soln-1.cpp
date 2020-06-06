class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // at time t, at most t
        // when there is a path go to (N - 1, N - 1)
        // find the shortest path whose cost is max of value of cost
        auto comp = [](const tuple<int, int, int> & a, const tuple<int, int, int> & b) {return get<0>(a) > get<0>(b);};
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(comp)> frontier(comp);
        const int N = grid.size();
        frontier.push({grid[0][0], 0, 0});
        int dirs[5] = {0, 1, 0, -1, 0};
        vector<bool> processed(N * N, false);
        vector<int> costs(N * N, N * N * 2);
        costs[0] = grid[0][0];
        const int target = N * N - 1;
        while (!frontier.empty()) {
            int cost, i, j;
            tie(cost, i, j) = frontier.top();
            int pos = i * N + j;
            if (pos == target) return cost; 
            frontier.pop();
            if (processed[pos]) continue;
            processed[pos] = true;
            for(int k = 0; k < 4; ++k) {
                int di = dirs[k], dj = dirs[k + 1];
                int ni = i + di, nj = j + dj;
                if (0 <= ni && ni < N && 0 <= nj && nj < N) {
                    int npos = ni * N + nj;
                    if (costs[npos] > max(costs[pos], grid[ni][nj])) {
                        costs[npos] = max(costs[pos], grid[ni][nj]);
                        frontier.push({costs[npos], ni, nj});
                    }
                }
            }
        }
        return -1;
    }
};
