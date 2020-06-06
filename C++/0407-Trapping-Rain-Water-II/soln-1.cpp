class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty() || heightMap[0].empty()) return 0;
        int m = heightMap.size(), n = heightMap[0].size();
        vector<tuple<int, int, int>> walls;
        for(int j = 0; j < n; ++j) {
            walls.emplace_back(-heightMap[0][j], 0, j);
            walls.emplace_back(-heightMap[m - 1][j], m - 1, j);
            heightMap[0][j] = heightMap[m - 1][j] = -1;
        }
        for(int i = 1; i < m - 1; ++i) {
            walls.emplace_back(-heightMap[i][0], i, 0);
            walls.emplace_back(-heightMap[i][n - 1], i, n - 1);
            heightMap[i][0] = heightMap[i][n - 1] = -1;
        }
        make_heap(walls.begin(), walls.end());
        int ans = 0;
        int dirs[5] = {1, 0, -1, 0, 1};
        while (!walls.empty()) {
            int wall, i, j;
            tie(wall, i, j) = walls.front();
            pop_heap(walls.begin(), walls.end());
            walls.pop_back();
            wall = -wall;
            for(int k = 0; k < 4; ++k) {
                int ni = i + dirs[k], nj = j + dirs[k + 1];
                if (0 <= ni && ni < m && 0 <= nj && nj < n && heightMap[ni][nj] != -1) {
                    ans += max(0, wall - heightMap[ni][nj]);
                    walls.emplace_back(-max(wall, heightMap[ni][nj]), ni, nj);
                    push_heap(walls.begin(), walls.end());
                    heightMap[ni][nj] = -1;
                }
            }
        }
        return ans;
    }
};
