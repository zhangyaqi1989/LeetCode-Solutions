class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        queue<pair<int, int>> frontier;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] = INT_MAX;
                } else {
                    frontier.push({i, j});
                }
            }
        }
        int step = 0;
        int dis[] = {0, 0, 1, -1};
        int djs[] = {1, -1, 0, 0};
        while (!frontier.empty()) {
            int size = frontier.size();
            for(int p = 0; p < size; ++p) {
                auto node = frontier.front();
                frontier.pop();
                int i = node.first, j = node.second;
                for(int k = 0; k < 4; ++k) {
                    int di = dis[k], dj = djs[k];
                    int newi = i + di, newj = j + dj;
                    if (0 <= newi && newi < m && 0 <= newj && newj < n) {
                        if (matrix[newi][newj] > matrix[i][j] + 1) {
                            matrix[newi][newj] = matrix[i][j] + 1;
                            frontier.push({newi, newj});
                        }
                    }
                }
            }
        }
        return matrix;
    }
};
