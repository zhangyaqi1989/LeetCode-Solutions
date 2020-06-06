class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        const int R = matrix.size(), C = matrix[0].size();
        vector<bool> visited(R * C, false);
        int r = 0, c = 0, dr = 0, dc = 1;
        // (0, 1) --> (1, 0) -> (0, -1)
        vector<int> nums;
        for(int i = 0; i < R * C; ++i) {
            nums.push_back(matrix[r][c]);
            visited[r * C + c] = true;
            int nr = r + dr, nc = c + dc;
            if (nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr * C + nc]) {
                int temp = dr;
                dr = dc;
                dc = -temp;
            }
            r = r + dr;
            c = c + dc;
        }
        return nums;
    }
};
