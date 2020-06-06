class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for(vector<int> & row : matrix) {
            for(int j = 1; j < n; ++j) {
                row[j] += row[j - 1];
            }
        }
        int cnt = 0;
        for(int left = 0; left < n; ++left) {
            for(int right = left; right < n; ++right) {
                unordered_map<int, int> memo;
                memo[0] = 1;
                int cur = 0;
                for(int i = 0; i < m; ++i) {
                    cur += matrix[i][right];
                    if (left > 0) cur -= matrix[i][left - 1];
                    cnt += memo[cur - target];
                    memo[cur] += 1;
                }
            }
        }
        return cnt;
    }
};
